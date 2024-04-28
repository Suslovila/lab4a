

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "Boolean.h"
#include "IOUtils.h"

int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255]) {
    char b[100];
    int width = 100;

    if (!tree) return 0;

    sprintf(b, "(%s: %d)", tree->key, tree->value);

    int left = _print_t(tree->left, 1, offset, depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }

    return left + width + right;
}

void print_t(Node *tree) {
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

char *copyString(char *string) {
    int length = strlen(string);
    char *result = calloc(length + 1, sizeof(char));
    for (int i = 0; i < length; i++) {
        result[i] = string[i];
    }
    return result;
}

Node *createNode(char *key, unsigned int value) {
    Node *node = malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->value = value;
    return node;
}

int max(int i1, int i2) {
    return i1 > i2 ? i1 : i2;
}

boolean isFirstBiggerThanSecond(char *bigger, char *smaller) {
    int lengthBigger = strlen(bigger);
    int lengthSmaller = strlen(smaller);
    int maxi = max(lengthBigger, lengthSmaller);
    for (int i = 0; i < maxi; i++) {
        if (bigger[i] > smaller[i]) {
            return true;
        }
        if (bigger[i] < smaller[i]) {
            return false;
        }
    }
    return false;
}

Node *insert(Node *underRoot, char *key, unsigned int value) {
    if (underRoot == NULL) {
        return createNode(key, value);
    }
    int cmp = strcmp(key, underRoot->key);
    if (cmp < 0) {
        underRoot->left = insert(underRoot->left, key, value);
    } else {
        underRoot->right = insert(underRoot->right, key, value);
    }
    return underRoot;
}


Node *findMin(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node *deleteNode(Node *root, char *key, int version, int accumulated) {
    if (root == NULL) {
        return root;
    }
    int cmp = strcmp(key, root->key);

    if (cmp < 0) {
        root->left = deleteNode(root->left, key, version, accumulated);
    } else if (cmp > 0) {
        root->right = deleteNode(root->right, key, version, accumulated);
    } else {
        if (version > accumulated) {
            accumulated += 1;
            root->right = deleteNode(root->right, root->key, version, accumulated);
        } else if (version < accumulated) {
            return root;
        } else {
            if (root->left != NULL && root->right != NULL) {
                Node *successor = findMin(root->right);
                free(root->key);
                root->key = successor->key;
                root->value = successor->value;
                accumulated += 1;
                root->right = deleteNode(root->right, root->key, version, accumulated);
            } else {
                if (root->left != NULL) {
                    root = root->left;
                } else if (root->right != NULL) {
                    root = root->right;
                } else {
                    freeNode(root);
                    root = NULL;
                }
            }
        }
    }
    return root;
}

//void printTree(Node *node, int level) {
//    int i = level;
//    if (node != NULL) {
//        printTree(node->right, level + 1);
//        while (i-- > 0) {
//            printf(" ");
//        }
//        printf("the key is: %s, the value is: %d \n", node->key, node->value);
//        printTree(node->left, level + 1);
//
//    }
//}

void printTree(struct Node *root, int level) {
    if (root != NULL) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("(%s: %d)\n", root->key, root->value);
        printTree(root->left, level + 1);
    }
}

Node *search(Node *root, char *key, int instance) {
    if (root == NULL || instance < 0) {
        return NULL;
    }

    int cmp = strcmp(key, root->key);

    if (cmp < 0) {
        return search(root->left, key, instance);
    } else if (cmp > 0) {
        return search(root->right, key, instance);
    } else {
        if (instance == 0) {
            return root;
        } else {
            return search(root->right, key, instance - 1);
        }
    }
}

void printNode(Node *node) {
    if (node == NULL) {
        printf("NULL");
        return;
    }
    printf("%s : %d\n", node->key, node->value);
}

void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);

    freeNode(root);
}

void freeNode(Node *node) {
    if (node == NULL) {
        return;
    }

    if (node->key != NULL) {
        free(node->key);
    }
    free(node);
}

void visitTree(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("the word: %s appears %d times\n", root->key, root->value);
    visitTree(root->left);
    visitTree(root->right);

}

void toLowerStr(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

void calculateWordAmount(FILE *file) {
    Node *tree = NULL;
    char *word = readWordFromFile(file);
    while (word != NULL) {
        toLowerStr(word);
        if (strcmp(word, "") != 0) {
            Node *node = search(tree, word, 0);
            if (node != NULL) {
                node->value = node->value + 1;
            } else {
                tree = insert(tree, word, 1);
            }
            word = readWordFromFile(file);
            continue;
        }
        free(word);
        word = readWordFromFile(file);
    }
    visitTree(tree);
    freeTree(tree);
}

