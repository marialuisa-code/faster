#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

int writeInFile(const char* filename, const char* mode, const char* text) {
    FILE* fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int result = fputs(text, fp);
    if (result == EOF) {
        printf("Error writing in %s\n", filename);
        fclose(fp);
        return -1;
    }

    result = fclose(fp);
    if (result != 0) {
        printf("Error closing %s\n", filename);
        return -1;
    }

    return 0;
}

/*
* Attend juste le nom du fichier
*/
void readFromFile(const char* filename) {
    FILE* fptr = fopen(filename, "r");

    char data[500];

    if (fptr == NULL)
    {
        printf("File failed to open.\n");
        return 1;
    }


    while (fgets(data, sizeof(data), fptr) != NULL)
    {
        printf("%s", data);
    }
    fclose(fptr);

}

char* extractPhrase(const char* filename) {
    char data[500];
    char* phrase = calloc(500, sizeof(char));
    FILE* fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("File failed to open.\n");
        return NULL;
    }

    if (phrase == NULL)
    {
        fclose(fptr);
        return NULL;
    }

    while (fgets(data, sizeof(data), fptr) != NULL)
    {
        printf("Ligne lue : %s\n", data);
        remplirTableauPhrase(data, phrase);
    }

    fclose(fptr);

    return phrase;
}

void remplirTableauPhrase(char* data, char* phrase) {
    int j = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        if (data[i] != ';')
        {
            phrase[j] = data[i];
            j++;
        }
    }

    phrase[j] = '\0';
}

int connaitreNombrePhrases(const char* filename) {
    FILE* fptr = fopen(filename, "r");
    char data[500];
    int nbPhrases = 0;

    if (fptr == NULL)
    {
        printf("File failed to open.\n");
        return -1;
    }

    while (fgets(data, sizeof(data), fptr) != NULL)
    {
        nbPhrases = nbPhrases + 1;
    }

    fclose(fptr);

    return nbPhrases;
}

char** tableauDePhrases(char* filename) {

    int nbPhrases = connaitreNombrePhrases(filename);

    if (nbPhrases < 0) {
        return NULL;
    }

    char** tableauPhrases = calloc(nbPhrases, sizeof(char*));

    if (tableauPhrases == NULL)
        return NULL;

    FILE* fptr = fopen(filename, "r");

    if (fptr == NULL) {
        free(tableauPhrases);
        return NULL;
    }

    char data[500];
    char unePhrase[500];
    int i = 0;

    while (i < nbPhrases && fgets(data, sizeof(data), fptr) != NULL) {

        remplirTableauPhrase(data, unePhrase);

        tableauPhrases[i] = malloc(strlen(unePhrase) + 1);

        if (tableauPhrases[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(tableauPhrases[j]);

            free(tableauPhrases);
            fclose(fptr);
            return NULL;
        }

        strcpy(tableauPhrases[i], unePhrase);

        i++;
    }

    fclose(fptr);

    return tableauPhrases;
}