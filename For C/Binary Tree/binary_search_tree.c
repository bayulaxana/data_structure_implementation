/**
 * Implementasi Binary Search Tree (ADT: set)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C
 */

#include <stdlib.h>
#include <stdbool.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING !!!
 * ---------------------------------------------
 * Utility functions below. 
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) {
        return __bst__createNode(value);
    }

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else
        if (value > root->right)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__remove(BSTNode *root, int value) {

}

/* 
==============================================
Primary function. Accessible and safe to use.|
==============================================
*/

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

void bst_insert(BST *bst, int value) {
    bst->_root = __bst__insert(bst->_root, value);
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_remove(BST *bst, int value) {

}

