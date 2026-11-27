#include <stdio.h>
#include <string.h>
#include "levenshtein.h"
#include "fichier.h"

#define MAX_NAME_LEN 50
#define MAX_LINE_LEN 200

int main(void)
{
    const char* filename = "score.txt";
    const char* phrases = "phrases.txt";

    int dist = distance("chat", 4, "chaton", 6);
    printf("Distance: %d\n", dist);

    char name[MAX_NAME_LEN];
    printf("Enter name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error reading name.\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0';   

    
    char line[MAX_LINE_LEN];
    snprintf(line, sizeof(line), "%s,%d\n", name, dist);

    if (writeInFile(filename, "w", "Name,Score\n") != 0) {   
        return 1;
    }
    if (writeInFile(filename, "a", line) != 0) {             
        return 1;
    }

    printf("\nData successfully written to %s\n", filename);

    printf("read from data");
    //readFromFile(phrases);
    extractPhrase(phrases);
    //tableauDePhrases("u","n","o");

    return 0;
}