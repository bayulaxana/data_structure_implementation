/*
-- Created by Bayu Laksana on 20 December 2019
-- Implemented for C (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>
#include <stdbool.h>

/* Node structue */

typedef struct bstnode_t {
    int key;
    struct bstnode_t    \
        *left,
        *right;
} BSTNode;

/* Actual structure */

typedef struct bst_t {
    BSTNode *_root;
    int _size;
} BST;

/* Function prototype */

// BST function

void bst_init(BST *bst);
bool bst_isEmpty(BST *bst);
void bst_insert(BST *bst, int value);
bool bst_find(BST *bst, int key);
void bst_delete(BST *bst, int key);

// Utility function

BSTNode* __bst_insert(BSTNode *root, int value);
BSTNode* __bst_find(BSTNode *root, int key);
BSTNode* __bst_delete(BSTNode *root, int key);