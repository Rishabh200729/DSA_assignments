#include <iostream>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node *prev, *next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class CircularLinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    int getSize() {
        if (!head) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.add(10);
    dll.add(20);
    dll.add(30);
    dll.add(40);
    cout << "Size of Doubly Linked List: " << dll.getSize() << endl;

    CircularLinkedList cll;
    cll.add(5);
    cll.add(15);
    cll.add(25);
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;

    return 0;
}