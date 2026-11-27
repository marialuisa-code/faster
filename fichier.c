#include <stdio.h>
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
    //lire le fichier
    FILE* fptr = fopen(filename, "rb");
    if (fptr == NULL)
    {
        printf("File failed to open.\n");
        return 1;
    }

    char data[500];
    char* phrase = calloc(100, sizeof(char));
   
    int i = 0;

    while (fgets(data, sizeof(data), fptr) != NULL)
    {
        printf("Ligne lue : %s\n", data);

        int j = 0;
        for (int i = 0; data[i] != '\0'; i++)
        {
            phrase[j] = data[i];
            j++;
        }

        phrase[j] = '\0';
    }

    
    
    //fermer ptr
    fclose(fptr);
    
    return phrase;

}

//apres faire un random sur le double tableau et l'indice sera celui de la phrase que l'utilisateur devra tapper

char** tableauDePhrases(char* unePhrase) {
    char** tableauPhrases = calloc(sizeof(unePhrase), sizeof(char*));
    return tableauPhrases;
}