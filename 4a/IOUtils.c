#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "IOUtils.h"

char *susReadline(const char *prompt) {

    char *ptr = malloc(1);
    char buffer[81];
    int n, len = 0;
    *ptr = '\0';
    printf("%s", prompt);

    do {
        n = scanf("%80[^\n]", buffer);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
        } else if (n == 0) {
            scanf("%*c");
        } else {
            len += strlen(buffer);
            ptr = realloc(ptr, len + 1);
            if (ptr == NULL) {
                return NULL;
            }
            ptr = strcat(ptr, buffer);
        }
    } while (n > 0);
    return ptr;
}

FILE *handleOpeningFile(char *interactionType) {
    printf("Enter file name\n");
    char *fileName = susReadline("");
    if (fileName == NULL) {
        return NULL;
    }
    printf("%s\n", fileName);
    FILE *file = fopen(fileName, interactionType);

    if (file == NULL) {
        printf("Failed to open file with name: %s\n", fileName);
        free(fileName);
        return NULL;
    }
    printf("opened file successfully\n");
    free(fileName);
    return file;
}


int readLineFromTextFile(FILE *file, char **pointer) {

    char *ptr = malloc(1);
    char buffer[81];
    int n, len = 0;
    *ptr = '\0';

    do {
        n = fscanf(file, "%80[^\n]", buffer);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
        } else if (n == 0) {
            fscanf(file, "%*c");
        } else {
            len += strlen(buffer);
            ptr = realloc(ptr, len + 1);
            if (ptr == NULL) {
                return 0;
            }
            ptr = strcat(ptr, buffer);
        }
    } while (n > 0);
    if (ptr == NULL) return 0;
    (*pointer) = ptr;
    return 1;
}


Node *handleTextFileImport(FILE *file) {

    Node *root = NULL;

    int flag = feof(file);
    while (!flag) {
        char *key = NULL;
        int value = 0;
        readLineFromTextFile(file, &key);
        fscanf(file, "%d\n", &value);
        root = insert(root, key, value);
        flag = feof(file);
    }

    return root;
}

void clearBuf() {
    scanf("%*[^\n]");
}


int
handleInput(int *pointer, int lowerBound, int upperBound, const char *greetingMessage, const char *wrongInputMessage) {
    int trigger = 0;
    printf("%s", greetingMessage);
    while (!trigger) {
        trigger = scanf("%d", pointer);
        if (trigger == EOF) {
            return EOF;
        }
        if (trigger == 0) {
            printf("Wrong format. Try again\n");
            clearBuf();
        } else if (*pointer < lowerBound || *pointer > upperBound) {
            printf("%s\n", wrongInputMessage);
            trigger = 0;
        }
    }
    return 1;
}

int handleStrokeInput(char *pointer, int minLength, int maxLength, const char *greetingMessage,
                      const char *wrongInputMessage) {
    int trigger = 0;
    printf("%s", greetingMessage);
    while (!trigger) {
        trigger = scanf("%s", pointer);
        if (trigger == EOF) {
            return EOF;
        }
        if (trigger == 0) {
            printf("Wrong format. Try again\n");
            clearBuf();
        } else if (strlen(pointer) < minLength || strlen(pointer) > maxLength) {
            printf("%s", wrongInputMessage);
            trigger = 0;
        }
    }
    return 1;
}


int readChar(FILE *file, char *ch) {
    *ch = fgetc(file);

    if (*ch == EOF) {
        return 0; // Достигнут конец файла
    } else if (*ch == '\n') {
        return 2; // Найден символ переноса строки
    } else {
        return 1; // Символ успешно считан
    }
}

char *readWordFromFile(FILE *file) {
    int flag = feof(file);
    if (flag != 0) {
        return NULL;
    }
    int length = 0;
    int expandFactor = 5;
    char *word = calloc(expandFactor, sizeof(char));
    while (flag == 0) {
        char symbol = 0;
        int success = readChar(file, &symbol);
        if (success == 2) {
            flag = feof(file);
            continue;
        }
        if (!((symbol <= 90 && symbol >= 65) || (symbol >= 97 && symbol <= 122))) {
            word[length] = 0;
//            word = realloc(word, sizeof(char) * length);
            return word;
        }
        word[length] = symbol;
        length += 1;
        if (length % expandFactor == 0) {
            word = realloc(word, sizeof(char) * (length + 1 + expandFactor));
        }
        flag = feof(file);
    }
    word[length] = 0;
//    word = realloc(word, sizeof(char) * length);
    return word;
}