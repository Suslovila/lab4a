//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "BinaryTree.h"
//
//
//Node* createNode(char key[], unsigned int value) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    strcpy(newNode->key, key);
//    newNode->value = value;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//Node* insert(Node* root, char key[], unsigned int value) {
//    if (root == NULL) {
//        return createNode(key, value);
//    }
//
//    int cmp = strcmp(key, root->key);
//    if (cmp < 0) {
//        root->left = insert(root->left, key, value);
//    } else if (cmp > 0) {
//        root->right = insert(root->right, key, value);
//    }
//
//    return root;
//}
//
//Node* findMin(Node* node) {
//    while (node->left != NULL) {
//        node = node->left;
//    }
//    return node;
//}
//
//Node* deleteNode(Node* root, char key[]) {
//    if (root == NULL) {
//        return root;
//    }
//
//    int cmp = strcmp(key, root->key);
//    if (cmp < 0) {
//        root->left = deleteNode(root->left, key);
//    } else if (cmp > 0) {
//        root->right = deleteNode(root->right, key);
//    } else {
//        if (root->left == NULL) {
//            Node* temp = root->right;
//            free(root);
//            return temp;
//        } else if (root->right == NULL) {
//            Node* temp = root->left;
//            free(root);
//            return temp;
//        }
//
//        Node* temp = findMin(root->right);
//        strcpy(root->key, temp->key);
//        root->value = temp->value;
//        root->right = deleteNode(root->right, temp->key);
//    }
//
//    return root;
//}
//
//void inorderTraversal(Node* root) {
//    if (root != NULL) {
//        inorderTraversal(root->left);
//        printf("Key: %s, Value: %u\n", root->key, root->value);
//        inorderTraversal(root->right);
//    }
//}
//
//Node* search(Node* root, char key[]) {
//    if (root == NULL || strcmp(root->key, key) == 0) {
//        return root;
//    }
//
//    int cmp = strcmp(key, root->key);
//    if (cmp < 0) {
//        return search(root->left, key);
//    } else {
//        return search(root->right, key);
//    }
//}
//
//int main() {
//    Node* root = NULL;
//
//    // Добавление элементов
//    root = insert(root, "apple", 10);
//    insert(root, "banana", 20);
//    insert(root, "orange", 30);
//
//    // Обход дерева
//    printf("Inorder traversal:\n");
//    inorderTraversal(root);
//
//    // Поиск элемента
//    char keyToSearch[] = "banana";
//    Node* foundNode = search(root, keyToSearch);
//    if (foundNode != NULL) {
//        printf("\nElement with key %s found in the tree. Value: %u\n", keyToSearch, foundNode->value);
//    } else {
//        printf("\nElement with key %s not found in the tree.\n", keyToSearch);
//    }
//
//    // Удаление элемента
//    char keyToDelete[] = "apple";
//    root = deleteNode(root, keyToDelete);
//
//    // Обход дерева после удаления
//    printf("Inorder traversal after deleting %s:\n", keyToDelete);
//    inorderTraversal(root);
//
//    return 0;
//}