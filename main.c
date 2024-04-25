#include <stdio.h>
#include "BinaryTree.h"
#include "stdlib.h"
#include "IOUtils.h"



int main() {
//    Node *root = NULL;
//
//    root = insert(root, "banana", 20);
//    root = insert(root, "apple", 10);
//    root = insert(root, copyString("apple"), 30);
//    root = deleteNode(root, "apple", 1, 0);
//    printTree(root, 1);
//    printNode(search(root, "apple", -1));
    FILE *file = handleOpeningFile("r");
    if (file != NULL) {
//        Node* root = handleTextFileImport(file);
//        print_t(root);
        calculateWordAmount(file);
        fclose(file);
//        freeTree(root);

    }
//    D_Timing();
    return 0;
}
