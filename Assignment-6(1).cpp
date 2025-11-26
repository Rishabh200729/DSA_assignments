#include <iostream>
using namespace std;

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    
    DLLNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    DLLNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertStart(int val) {
        DLLNode* newNode = new DLLNode(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << val << " at the start" << endl;
    }

    void insertLast(int val) {
        DLLNode* newNode = new DLLNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DLLNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << val << " at the end" << endl;
    }

    void insertAfter(int target, int val) {
        DLLNode* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node " << target << " not found."<<endl;
            return;
        }
        DLLNode* newNode = new DLLNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        cout << "Inserted " << val << " after " << target << ".\n";
    }

    void insertBefore(int target, int val) {
        if (head == nullptr) return;
        
        if (head->data == target) {
            insertStart(val);
            return;
        }

        DLLNode* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << target << " not found"<< endl;
            return;
        }

        DLLNode* newNode = new DLLNode(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << "Inserted " << val << " before " << target << "." << endl;
    }

    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        DLLNode* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node " << val << " not found.\n";
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
        }
        else if (temp->next == nullptr) {
            temp->prev->next = nullptr;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Node " << val << " deleted.\n";
    }
    void search(int val) {
        DLLNode* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << val << " not found in the list.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        DLLNode* temp = head;
        cout << "DLL: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

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

    void insertStart(int val) {
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
            head = newNode;
        }
        cout << "Inserted " << val << " at the start.\n";
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

    void insertAfter(int target, int val) {
        if (head == nullptr) return;
        CLLNode* temp = head;
        do {
            if (temp->data == target) {
                CLLNode* newNode = new CLLNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << val << " after " << target << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << target << " not found.\n";
    }

    void insertBefore(int target, int val) {
        if (head == nullptr) return;

        if (head->data == target) {
            insertStart(val);
            return;
        }

        CLLNode* temp = head;
        CLLNode* prev = nullptr;
        do {
            if (temp->data == target) {
                CLLNode* newNode = new CLLNode(val);
                newNode->next = temp;
                prev->next = newNode;
                cout << "Inserted " << val << " before " << target << ".\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << target << " not found.\n";
    }

    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        CLLNode* curr = head;
        CLLNode* prev = nullptr;

        while (curr->data != val) {
            if (curr->next == head) {
                cout << "Node " << val << " not found.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        if (curr->next == head && curr == head) {
            head = nullptr;
            delete curr;
            cout << "Node " << val << " deleted. List is now empty.\n";
            return;
        }

        if (curr == head) {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = head->next;
            prev->next = head;
            delete curr;
        }
        else {
            prev->next = curr->next;
            delete curr;
        }
        cout << "Node " << val << " deleted.\n";
    }

    void search(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        CLLNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << val << " not found.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        CLLNode* temp = head;
        cout << "CLL: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)\n";
    }
};

void subMenu(int listType) {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, val, target;

    while (true) {
        cout << "\n--- " << (listType == 1 ? "Doubly" : "Circular") << " Linked List Operations ---\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at Last\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a specific Node\n";
        cout << "6. Search for a Node\n";
        cout << "7. Display List\n";
        cout << "8. Return to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 8) break;

        switch (choice) {
        case 1:
            cout << "Enter value: "; cin >> val;
            if (listType == 1) dll.insertStart(val); else cll.insertStart(val);
            break;
        case 2:
            cout << "Enter value: "; cin >> val;
            if (listType == 1) dll.insertLast(val); else cll.insertLast(val);
            break;
        case 3:
            cout << "Enter target node: "; cin >> target;
            cout << "Enter new value: "; cin >> val;
            if (listType == 1) dll.insertAfter(target, val); else cll.insertAfter(target, val);
            break;
        case 4:
            cout << "Enter target node: "; cin >> target;
            cout << "Enter new value: "; cin >> val;
            if (listType == 1) dll.insertBefore(target, val); else cll.insertBefore(target, val);
            break;
        case 5:
            cout << "Enter value to delete: "; cin >> val;
            if (listType == 1) dll.deleteNode(val); else cll.deleteNode(val);
            break;
        case 6:
            cout << "Enter value to search: "; cin >> val;
            if (listType == 1) dll.search(val); else cll.search(val);
            break;
        case 7:
            if (listType == 1) dll.display(); else cll.display();
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

int main() {
    int mainChoice;
    while (true) {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Select List Type: ";
        cin >> mainChoice;

        if (mainChoice == 3) {
            cout << "Exiting program.\n";
            break;
        } else if (mainChoice == 1 || mainChoice == 2) {
            subMenu(mainChoice);
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}