#pragma once
#include <stdio.h>

int writeInFile(const char* filename, const char* mode, const char* text);

void readFromFile(const char* filename);

char* extractPhrase(const char* filename);

void remplirTableauPhrase(char* data, char* phrase);

int connaitreNombrePhrases(const char* filename);

char** tableauDePhrases(char* unePhrase);