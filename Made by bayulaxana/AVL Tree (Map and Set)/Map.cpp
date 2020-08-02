/** 
 * [MADE WITH ❤ by BAYU LAKSANA]
 * 
 * Here is a comprehensive and elegant implementation of
 * Map Abstract Data Type (ADT) using AVL Tree Data Structures
 * 
 * Read the Documentation on README
 * https://github.com/AlproITS/StrukturData/blob/master/Made%20by%20bayulaxana/AVL%20Tree%20(Map%20and%20Set)/README.md
 */  

#include <iostream>
#include <algorithm>
#include <stack>

/**
 * "NodeData" is used to store
 * the key-value pair, the basic behaviour
 * of Map ADT.
 * 
 * [ Default data type ]
 * - key    : int
 * - value  : int
 */
struct NodeData {
    int key, value;
};

/**
 * "Node" represents a node in AVL-Tree
 */
struct Node {
    NodeData data;
    Node *left, *right;
    int height, balanceFactor;

    Node() {}
    Node(NodeData &keyValue)
    {
        left = nullptr;
        right = nullptr;
        data.key = keyValue.key;
        data.value = keyValue.value;
    }
};

/**
 * Map ADT implementation using AVL-Tree
 * [ Default data type ]
 * - key    : int
 * - value  : int
 */
class Map
{
    Node *_root;
    unsigned _size;

    void _update(Node *node) {
        int leftNodeHeight  = (node->left == nullptr) ? -1 : node->left->height;
        int rightNodeHeight = (node->right == nullptr) ? -1 : node->right->height;

        node->height = 1 + std::max(leftNodeHeight, rightNodeHeight);
        node->balanceFactor = rightNodeHeight - leftNodeHeight;
    }

    Node* _rightRotation(Node *node) {
        Node *newParent = node->left;
        node->left = newParent->right;
        newParent->right = node;
        _update(node);
        _update(newParent);
        return newParent;
    }

    Node* _leftRotation(Node *node) {
        Node *newParent = node->right;
        node->right = newParent->left;
        newParent->left = node;
        _update(node);
        _update(newParent);
        return newParent;
    }

    Node* _leftLeft(Node *node) {
        return _rightRotation(node);
    }

    Node* _rightRight(Node *node) {
        return _leftRotation(node);
    }

    Node* _leftRight(Node *node) {
        node->left = _leftRotation(node->left);
        return _leftLeft(node);
    }

    Node* _rightLeft(Node *node) {
        node->right = _rightRotation(node->right);
        return _rightRight(node);
    }

    Node* _balance(Node *node) {
        if (node->balanceFactor == -2) {
            if (node->left->balanceFactor <= 0)
                return _leftLeft(node);
            else
                return _leftRight(node);
        }
        else if (node->balanceFactor == 2) {
            if (node->right->balanceFactor >= 0)
                return _rightRight(node);
            else
                return _rightLeft(node);
        }
        return node;
    }

    Node* _search(Node *node, int key) {
        while (node != nullptr) {
            if (key < node->data.key)
                node = node->left;
            else if (key > node->data.key)
                node = node->right;
            else
                return node;
        }
        return node;
    }

    Node* _insert(Node *node, NodeData &keyValuePair) {
        if (node == nullptr) return new Node(keyValuePair);

        if (keyValuePair.key < node->data.key)
            node->left = _insert(node->left, keyValuePair);
        else if (keyValuePair.key > node->data.key)
            node->right = _insert(node->right, keyValuePair);
        else
            node->data = keyValuePair;
        
        _update(node);
        return _balance(node);
    }

    Node* _deleteAll(Node *node) {
        if (node == nullptr) return nullptr;

        node->left = _deleteAll(node->left);
        node->right = _deleteAll(node->right);

        delete node;
        return nullptr;
    }

public:
    Map(): _size(0U), _root(nullptr)
    {}

    ~Map() {
        clear();
        delete _root;
    }
    
    bool isEmpty() {
        return _root == nullptr;
    }

    unsigned size() {
        return _size;
    }

    void clear() {
        _root = _deleteAll(_root);
        _size = 0U;
    }

    bool exist(int key) {
        Node *temp = _search(_root, key);
        if (!temp) return false;
        return (temp->data.key == key);
    }

    void insert(NodeData keyValuePair) {
        if (!exist(keyValuePair.key)) {
            _root = _insert(_root, keyValuePair);
            _size++;
        }
    }

    void assign(NodeData keyValuePair) {
        if (!exist(keyValuePair.key)) {
            _root = _insert(_root, keyValuePair);
            _size++;
        }
        else {
            _root = _insert(_root, keyValuePair);
        }
    }

    void remove(int key) {
        if (exist(key)) {
            // _root = 
            _size--;
        }
    }

    int getValue(int key) {
        if (exist(key))
            return _search(_root, key)->data.value;
        else exit(-1);
    }
};

int main(int argc, char const *argv[])
{
    Map mp;

    // Map::assign( {key, value} );
    // insert key-value pairs if doesn't exist yet, or
    // change the value of already-inserted key
    mp.assign({11, 23});
    mp.assign({1, 16});
    mp.assign({9, 12});
    mp.assign({9, 100});

    // Map::getValue(key)
    // get the value of already-inserted key-value pairs
    int foo = mp.getValue(1);
    std::cout << foo << '\n';
    return 0;
}
