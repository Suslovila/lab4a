#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "IOUtils.h"
#include "DotIntegration.h"


void handleInserting(Node *root);

void handleDeleting(Node *root);

void handleSearchingElement(Node *root);



void calc() {
    FILE *file = handleOpeningFile("r");
    if (file != NULL) {
        calculateWordAmount(file);
        fclose(file);
    }
}

int main() {

    Node* root = NULL;
    int mode = 0;
    while (mode != 7) {
        if (handleInput(&mode, 0, 7,
                        "0 - handle export to dot file\n 1 - insert element\n2 - delete element by key\n3 - find element by key\n4 - import from file \n5 - print tree\n6 - calculate word amount\n7 - exit\n",
                        "Wrong index. Try again\n") == EOF) {
            printf("got EOF\n");
            return EOF;
        }
        switch (mode) {
            case 0: {
                handleDotFileExport(root);
                break;
            }
            case 1: {
                scanf("%*c");
                printf("Enter key: ");
                char *key = susReadline("");
                if (key == NULL) {
                    printf("Error reading key\n");
                    break;
                }
                int value = 0;
                if (handleInput(&value, INT_MIN, INT_MAX,
                                "Enter value: ",
                                "Wrong input. Try again\n") == EOF) {
                    printf("got EOF\n");
                    free(key);
                    break;
                }
                root = insert(root, key, value);

                printf("The tree now is\n");
                printTreeVer2(root);
                break;
            }
            case 2: {
                if (root == NULL) {
                    printf("Tree is empty\n");
                    break;
                }
                printf("Enter key:");
                scanf("%*c");
                char *key = susReadline("");
                if (key == NULL) {
                    printf("Error reading key\n");
                }
                int version = 0;
                if (handleInput(&version, INT_MIN, INT_MAX,
                                "Enter version: ",
                                "Wrong input. Try again\n") == EOF) {
                    printf("got EOF\n");
                    free(key);
                    break;
                }
                Node* element = deleteNode(root, key, version, 0);
                if (element == NULL) {
                    printf("No element with key %s", key);
                } else {
                    printf("deleted: ");
                    printNode(element);
                    printf("\n");
                    freeNode(element);
                }
                free(key);

                printf("The root now is\n");
                printTreeVer2(root);
                break;
            }
            case 3: {
                handleSearchingElement(root);
                break;
            }
            case 4: {
                FILE *file = handleOpeningFile("r");
                if (file != NULL) {
                    freeTree(root);
                    root = handleTextFileImport(file);
                    printf("The root now is\n");
                    printTreeVer2(root);
                    fclose(file);
                }
                break;
            }
            case 5 : {
                printTreeVer2(root);
                break;
            }
            case 6 : {
                calc();
                break;
            }
            case 7: {
                break;
            }
        }
    }
    freeTree(root);
}



void handleSearchingElement(Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Enter key:");
    scanf("%*c");
    char *key = susReadline("");
    if (key == NULL) {
        printf("Error reading key\n");
    }

    int version = 0;
    if (handleInput(&version, INT_MIN, INT_MAX,
                    "Enter version: ",
                    "Wrong input. Try again\n") == EOF) {
        printf("got EOF\n");
        free(key);
        return;
    }
    Node* found = search(root, key, version);
    printf("Found: ");
    printNode(found);
    printf("\n");
    free(key);
    printf("The root now is\n");
    printTreeVer2(root);
}

void handleDeleting(Node *root) {

}

void handleInserting(Node *root) {
    scanf("%*c");
    printf("Enter key: ");
    char *key = susReadline("");
    if (key == NULL) {
        printf("Error reading key\n");
        return;
    }
    int value = 0;
    if (handleInput(&value, INT_MIN, INT_MAX,
                    "Enter value: ",
                    "Wrong input. Try again\n") == EOF) {
        printf("got EOF\n");
        free(key);
        return;
    }
    root = insert(root, key, value);

    printf("The tree now is\n");
    printTreeVer2(root);
}