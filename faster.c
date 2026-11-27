#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "levenshtein.h"
#include "fichier.h"

#define MAX_NAME_LEN 50
#define MAX_LINE_LEN 200

int main(void)
{
    const char* score = "score.txt";
    const char* phrases = "phrases.txt";

    //int dist = distance("chat", 4, "chaton", 6);
    //printf("Distance: %d\n", dist);

    //char name[MAX_NAME_LEN];
    //printf("Enter name: ");
    //if (fgets(name, sizeof(name), stdin) == NULL) {
    //    printf("Error reading name.\n");
    //    return 1;
    //}
    //name[strcspn(name, "\n")] = '\0';   

    //
    //char line[MAX_LINE_LEN];
    //snprintf(line, sizeof(line), "%s,%d\n", name, dist);

    //if (writeInFile(score, "w", "Name,Score\n") != 0) {
    //    return 1;
    //}
    //if (writeInFile(score, "a", line) != 0) {
    //    return 1;
    //}

    //printf("\nData successfully written to %s\n", score);

    printf("read from data");
    extractPhrase(phrases);
    char* phrase = extractPhrase(phrases);

    if (phrase == NULL)
    {
        printf("Erreur lors de l'extraction de la phrase.\n");
        return 1;
    }

    printf("\nPhrase extraite : %s\n", phrase);
    //apres faire un random sur le double tableau et l'indice sera celui de la phrase que l'utilisateur devra tapper


    free(phrase);

    return 0;
}