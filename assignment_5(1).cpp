#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val){ data = val; next = NULL; }
};

Node* head = NULL;

void insertBeg(int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertEnd(int val){
    Node* n = new Node(val);
    if(!head){ head = n; return; }
    Node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}

void insertBefore(int key, int val){
    if(!head) return;
    if(head->data == key){ insertBeg(val); return; }
    Node* t = head;
    while(t->next && t->next->data != key) t = t->next;
    if(!t->next) return;
    Node* n = new Node(val);
    n->next = t->next;
    t->next = n;
}

void insertAfter(int key, int val){
    Node* t = head;
    while(t && t->data != key) t = t->next;
    if(!t) return;
    Node* n = new Node(val);
    n->next = t->next;
    t->next = n;
}

void delBeg(){
    if(!head) return;
    Node* t = head;
    head = head->next;
    delete t;
}

void delEnd(){
    if(!head) return;
    if(!head->next){ delete head; head = NULL; return; }
    Node* t = head;
    while(t->next->next) t = t->next;
    delete t->next;
    t->next = NULL;
}

void delSpecific(int key){
    if(!head) return;
    if(head->data == key){ delBeg(); return; }
    Node* t = head;
    while(t->next && t->next->data != key) t = t->next;
    if(!t->next) return;
    Node* d = t->next;
    t->next = d->next;
    delete d;
}

void searchNode(int key){
    Node* t = head; int pos = 1;
    while(t){
        if(t->data == key){ cout << pos << endl; return; }
        pos++; t = t->next;
    }
    cout << -1 << endl;
}

void display(){
    Node* t = head;
    while(t){ cout << t->data << " "; t = t->next; }
    cout << endl;
}

int main(){
    int ch, val, key;
    while(1){
        cin >> ch;
        switch(ch){
            case 1: cin >> val; insertBeg(val); break;
            case 2: cin >> val; insertEnd(val); break;
            case 3: cin >> key >> val; insertBefore(key,val); break;
            case 4: cin >> key >> val; insertAfter(key,val); break;
            case 5: delBeg(); break;
            case 6: delEnd(); break;
            case 7: cin >> key; delSpecific(key); break;
            case 8: cin >> key; searchNode(key); break;
            case 9: display(); break;
            default: exit(0);
        }
    }
}
