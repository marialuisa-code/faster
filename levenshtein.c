#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levenshtein.h"

int distance(const char* mot1, int len1, const char* mot2, int len2) {
    int** matrix = malloc((len1 + 1) * sizeof(int*));
    if (matrix == NULL) return -1;

    for (int i = 0; i <= len1; i++) {
        matrix[i] = calloc(len2 + 1, sizeof(int));
        if (matrix[i] == NULL) {
            viderMemoire(matrix, i - 1);  
            return -1;
        }
    }

    for (int i = 0; i <= len1; i++) matrix[i][0] = i;
    for (int j = 0; j <= len2; j++) matrix[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        char c1 = mot1[i - 1];
        for (int j = 1; j <= len2; j++) {
            char c2 = mot2[j - 1];
            if (c1 == c2) {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else {
                int delete_ = matrix[i - 1][j] + 1;
                int insert_ = matrix[i][j - 1] + 1;
                int substitute = matrix[i - 1][j - 1] + 1;
                matrix[i][j] = (delete_ < insert_) ? delete_ : insert_;
                if (substitute < matrix[i][j]) matrix[i][j] = substitute;
            }
        }
    }

    int result = matrix[len1][len2];
    viderMemoire(matrix, len1);   
    return result;
}

void viderMemoire(int** matrix, int len1) {
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
}