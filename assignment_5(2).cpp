#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int v){ data=v; next=NULL; }
};

void countDelete(Node*& head, int key){
    int cnt=0;
    while(head && head->data==key){ Node* t=head; head=head->next; delete t; cnt++; }
    Node* cur=head;
    while(cur && cur->next){
        if(cur->next->data==key){
            Node* t=cur->next;
            cur->next=cur->next->next;
            delete t; cnt++;
        } else cur=cur->next;
    }
    cout << "Count: " << cnt << endl;
    Node* t=head; 
    while(t){ cout << t->data; if(t->next) cout<<"->"; t=t->next; }
    cout << endl;
}

int main(){
    vector<int> v={1,2,1,2,1,3,1};
    Node* head=NULL; Node* tail=NULL;
    for(int x:v){ Node* n=new Node(x); if(!head) head=tail=n; else{ tail->next=n; tail=n; } }
    countDelete(head,1);
}
