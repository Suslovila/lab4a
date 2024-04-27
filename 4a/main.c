#include <stdio.h>
#include "BinaryTree.h"
#include "stdlib.h"
#include "IOUtils.h"


void calc() {
    FILE *file = handleOpeningFile("r");
    if (file != NULL) {
        calculateWordAmount(file);
        fclose(file);
    }
}










//int main() {
////    Node *root = NULL;
////
////    root = insert(root, "banana", 20);
////    root = insert(root, "apple", 10);
////    root = insert(root, copyString("apple"), 30);
////    root = deleteNode(root, "apple", 1, 0);
////    printTree(root, 1);
////    printNode(search(root, "apple", -1));
////    calc();
////    D_Timing();
//    FILE *file = handleOpeningFile("r");
//    if (file != NULL) {
//        Node* root = handleTextFileImport(file);
//        printTreeVer2(root);
//        freeTree(root);
//        fclose(file);
//    }
//
//return 0;
//
//}
