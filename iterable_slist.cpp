#include <iostream>
#include <functional>
#include <forward_list>
#include <list>

using namespace std;

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node *next;
    };
    Node *head;
    
    Node* createNode(const T &data) {
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;
        
        return temp;
    }

public:
    List() : head(nullptr) {}
    
    class iterator;
    
    /**
     * iterator function here
     * begin() & end()
     */
    iterator begin() { return iterator(head);}
    iterator end() {return iterator(nullptr);}

    /**
     * List function
     * - push_back()
     */
    void pushBack(T data) {
        Node *newNode = createNode(data);

        if (!head) {
            head = newNode;
        }
        else {
            Node *temp = head;
            while (temp->next) 
                temp = temp->next;
            
            temp->next = newNode;
        }
    }

    class iterator {
    private:
        Node *currNode;

    public:
        iterator() : currNode(nullptr) {}
        iterator(Node *node) : currNode(node) {}

        iterator& operator=(Node *pnode) {
            this->currNode = pnode;
            return *this;
        }

        iterator& operator++() {
            if (currNode)
                currNode = currNode->next;
            return *this;
        }

        iterator operator++(int) {
            iterator it = *this;
            ++*this;
            return it;
        }

        bool operator!=(const iterator &other) {
            return currNode != other.currNode;
        }

        T operator*() {
            return currNode->data;
        }
    };
};

int main(int argc, char const *argv[])
{
    List<int> a;
    a.pushBack(23);
    a.pushBack(1);
    a.pushBack(11);
    return 0;
}
