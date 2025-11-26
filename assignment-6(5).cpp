#include <iostream>
using namespace std;

class LinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void createCycle() {
        if (!head) return;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (!head) return true;
        Node* temp = head->next;
        while (temp != nullptr && temp != head) {
            temp = temp->next;
        }
        return (temp == head);
    }
};

int main() {
    LinkedList list1;
    list1.add(10);
    list1.add(20);
    list1.add(30);

    LinkedList list2;
    list2.add(10);
    list2.add(20);
    list2.add(30);
    list2.createCycle();

    cout << "List 1 is circular: " << (list1.isCircular() ? "true" : "false") << endl;
    cout << "List 2 is circular: " << (list2.isCircular() ? "true" : "false") << endl;

    return 0;
}