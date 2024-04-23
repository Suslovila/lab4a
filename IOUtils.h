//
// Created by Илья on 23.03.2024.
//

#ifndef LAB3_IOUTILS_H
#define LAB3_IOUTILS_H


#include <stdio.h>
#include "BinaryTree.h"

char *susReadline(const char *prompt);
FILE* handleOpeningFile(char *interactionType);
Node* handleTextFileImport(FILE* file);
//int handleTextFileExport(FILE *file, Nop *table);
int readLineFromTextFile(FILE *file, char **pointer);
int handleInput(int *pointer, int lowerBound, int upperBound, const char *greetingMessage, const char *wrongInputMessage);
int handleStrokeInput(char *pointer, int minLength, int maxLength, const char *greetingMessage, const char *wrongInputMessage);
void clearBuf();
char* readWordFromFile(FILE* file);
int D_Timing();
void print_t(Node *tree);
char *copyString(char *string);

#endif //LAB3_IOUTILS_H


// kgmelkgmeglkermglekrmgerlkgmerlkg