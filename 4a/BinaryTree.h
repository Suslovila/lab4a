//
// Created by Илья on 17.04.2024.
//

#ifndef LAB4A_BINARYTREE_H
#define LAB4A_BINARYTREE_H

typedef struct Node {
    char *key;
    unsigned int value;

    struct Node* left;
    struct Node* right;

} Node;

Node *createNode(char *key, unsigned int value);
Node *insert(Node *underRoot, char *key, unsigned int value);
Node *deleteNode(Node *root, char *key, int version, int accumulated);
void printTree(Node *node, int level);
void printNode(Node *node);
Node *search(Node *root, char *key, int instance);
void freeTree(Node *root);
void freeNode(Node* node);
void calculateWordAmount(FILE* file);
void printTreeVer2(Node *root);
#endif //LAB4A_BINARYTREE_H
