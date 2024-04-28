#include "stdio.h"
#include "BinaryTree.h"
#include "IOUtils.h"

void printDotEdges(FILE *dotFile, Node *node) {
    if (node == NULL) return;
    if (node->left != NULL) {
        fprintf(dotFile, "%s->%s\n", node->key, node->left->key);
    }
    if (node->right != NULL) {
        fprintf(dotFile, "%s->%s\n", node->key, node->right->key);
    }
}


void printTreeToFile(Node *root, FILE *file) {
    if (root == NULL) {
        return;
    }
    printDotEdges(file, root);
    if (root->left != NULL) printTreeToFile(root->left, file);
    if (root->right != NULL) printTreeToFile(root->right, file);
}


void printRecursiveNode(Node *root, FILE *dotFile) {
    fprintf(dotFile, "digraph BinaryTree {\n");
    printTreeToFile(root, dotFile);
    fprintf(dotFile, "}\n");
}


int handleDotFileExport(Node* root) {
    FILE *dotFile = handleOpeningFile("w");
    if (dotFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    printRecursiveNode(root, dotFile);
    fclose(dotFile);

    return 0;
}