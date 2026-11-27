#pragma once
#include <stdio.h>

int writeInFile(const char* filename, const char* mode, const char* text);

void readFromFile(const char* filename);

char* extractPhrase(const char* filename);

char** tableauDePhrases(char* unePhrase);