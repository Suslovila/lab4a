//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "BinaryTree.h"
//
//Node *createNode(char *key, unsigned int value) {
//    Node *newNode = (Node *) malloc(sizeof(Node));
//    newNode->key = strdup(key);
//    newNode->value = value;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//Node *insert(Node *root, char *key, unsigned int value) {
//    if (root == NULL) {
//        return createNode(key, value);
//    }
//
//    int cmp = strcmp(key, root->key);
//    if (cmp == 0) {
//        root->right = insert(root->right, key, value);
//    } else if (cmp < 0) {
//        root->left = insert(root->left, key, value);
//    } else {
//        root->right = insert(root->right, key, value);
//    }
//
//    return root;
//}
//
//Node *findMin(Node *node) {
//    while (node->left != NULL) {
//        node = node->left;
//    }
//    return node;
//}
//
//Node *deleteNode(Node *root, char *key, int instance) {
//    if (root == NULL) {
//        return root;
//    }
//
//    int cmp = strcmp(key, root->key);
//    if (cmp < 0) {
//        root->left = deleteNode(root->left, key, instance);
//    } else if (cmp > 0) {
//        root->right = deleteNode(root->right, key, instance);
//    } else {
//        if (instance > 1) {
//            root->right = deleteNode(root->right, key, instance - 1);
//        } else {
//            if (root->right == NULL) {
//                Node *temp = root->left;
//                free(root->key);
//                free(root);
//                return temp;
//            } else if (root->left == NULL) {
//                Node *temp = root->right;
//                free(root->key);
//                free(root);
//                return temp;
//            }
//
//            Node *temp = findMin(root->right);
//            free(root->key);
//            root->key = strdup(temp->key);
//            root->value = temp->value;
//            root->right = deleteNode(root->right, temp->key, 1);
//        }
//    }
//
//    return root;
//}
//
//void reverseInorderTraversal(Node *root, char *low, char *high) {
//    if (root == NULL) {
//        return;
//    }
//
//    int cmpLow = strcmp(low, root->key);
//    int cmpHigh = strcmp(high, root->key);
//
//    reverseInorderTraversal(root->right, low, high);
//
//    if (cmpLow <= 0 && cmpHigh >= 0) {
//        printf("Key: %s, Value: %u\\n", root->key, root->value);
//    }
//
//    reverseInorderTraversal(root->left, low, high);
//}
//
//Node *search(Node *root, char *key, int instance) {
//    if (root == NULL) {
//        return NULL;
//    }
//
//    int cmp = strcmp(key, root->key);
//
//    if (cmp < 0) {
//        return search(root->left, key, instance);
//    } else if (cmp > 0) {
//        return search(root->right, key, instance);
//    } else {
//        if (instance > 1) {
//            return search(root->right, key, instance - 1);
//        } else {
//            return root;
//        }
//    }
//}
//
//Node *findClosestKey(Node *root, char *key) {
//    Node *closest = NULL;
//
//    while (root != NULL) {
//        if (strcmp(key, root->key) < 0) {
//            closest = root;
//            root = root->left;
//        } else {
//            root = root->right;
//        }
//    }
//
//    return closest;
//}