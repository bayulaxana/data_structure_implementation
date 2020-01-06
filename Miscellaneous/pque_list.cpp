#include <iostream>
#include <cstdlib>
using namespace std;

struct PriorityQueue 
{
    struct Node {
        int data;
        Node *next;
    } *head;
    unsigned size;

    PriorityQueue(){
        init();
    }
    
    void init() {
        head = NULL;
        size = 0;
    }

    Node* createNode(int data) {
        Node *tmp = (Node*) malloc(sizeof(Node));
        tmp->data = data;
        tmp->next = NULL;
        return tmp;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    int top() {
        if (!isEmpty()) return head->data;
        return 0; 
    }

    void pop() {
        if (!isEmpty()) {
            Node *temp = head;
            head = head->next;
            free(temp);
        }
    }

    void push(int data) {
        Node *temp = head;
        Node *newNode = createNode(data);

        if (isEmpty()) {
            head = createNode(data);
            return;
        }

        if (data < head->data) {
            newNode->next = head;
            head = newNode;
        }
        else {
            while ( temp->next != NULL && 
                    temp->next->data < data ) 
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void print() {
        Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        puts("");
    }
};

int main(int argc, char const *argv[])
{
    PriorityQueue pq;
    pq.push(3);
    pq.push(5);
    pq.push(8);
    pq.push(6);
    pq.push(1);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    return 0;
}

// 3 5 8
// push 6
// 