#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "BinaryTree.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int minInt(int a, int b){
    return a < b ? a : b;
}

int maxInt(int a, int b){
    return a > b ? a : b;
}

char *randomString(int length) {
    char *result = malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        int randomInt = abs(rand()) % 122;
        result[i] = (char)(maxInt(97, randomInt));
    }
    result[length] = '\0';
    return result;
}

int D_Timing() {
    Node *root = NULL;
    int keyLength = 3;
    int keyIterAmount = 10000;
    char* keys[keyIterAmount];
    int n = 10, k, cnt = 100000;
    clock_t first, last;
    srand(time(NULL));
    while (n-- > 0) {
        for(int i = 0; i < keyIterAmount; i++){
            keys[i] = randomString(keyLength);
        }
        for (int index = 0; index < cnt; index++) {
            char* randomStr = randomString(keyLength);
            root = insert(root, randomStr, 454);
        }
        int m = 0;
        first = clock();
        for (int i = 0; i < 10000; ++i) {
            if (search(root, keys[i], 0) != NULL) {
                ++m;
            }
            free(keys[i]);
        }
        last = clock();
        printf("%d items was found\n", m);
        printf("test #%d, number of nodes = %d, time = %f\n", 10 - n, (10 - n) * cnt, ((float)(last - first)) / CLOCKS_PER_SEC);
    }
    printf("Freesged");

    freeTree(root);
    printf("Freesged");
    return 1;
}