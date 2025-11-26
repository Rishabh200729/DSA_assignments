#include<iostream>
using namespace std;

struct CLLNode {
    int data;
    CLLNode* next;
    CLLNode(int val){
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    private:
        CLLNode* head;  
    public:
        CircularLinkedList() {  
            head = nullptr;
        }
        
        void insertLast(int val) {
            CLLNode* newNode = new CLLNode(val);
            if (head == nullptr) {
                head = newNode;
                newNode->next = head;
            } else {
                CLLNode* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
            }
            cout << "Inserted " << val << " at the end.\n";
        }
        
        void display() {
            if(!head) {
                cout << "List is empty.\n";
                return;
            }
            CLLNode* temp = head;
            do{
                cout << temp->data << "\t" ;
                temp = temp->next;
            }while(temp != head);
            cout << temp->data << endl;
        }
};

int main(){
    CircularLinkedList cll;
    cll.insertLast(1);
    cll.insertLast(2);
    cll.insertLast(3);
    cll.display();
    return 0;
}