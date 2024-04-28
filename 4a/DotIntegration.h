//
// Created by Илья on 28.04.2024.
//

#ifndef LAB4A_DOTINTEGRATION_H
#define LAB4A_DOTINTEGRATION_H

#include <stdio.h>
#include "BinaryTree.h"

void printDotEdges(FILE *dotFile, Node *node);


void printTreeToFile(Node *root, FILE *file);


void printRecursiveNode(Node *root, FILE *dotFile);

int handleDotFileExport(Node* root);

#endif //LAB4A_DOTINTEGRATION_H
