#include <iostream>
using namespace std;
// Write a program to check if a doubly linked list of characters is palindrome or not.

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

    bool checkPalindrome(){
        Node* end = head;
        Node* start = head;
        while(end->next != NULL){
            end = end->next;
        }
        while(start != end){
            if(start->data != end->data) return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }
};


int main() {
    DoublyLinkedList dll;
    dll.add(10);
    dll.add(20);
    dll.add(30);
    dll.add(20);
    dll.add(10);
    cout << (dll.checkPalindrome() ? "Palindrome": "Not a palindrome.") << endl;  
    return 0;
}