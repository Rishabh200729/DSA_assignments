#include <bits/stdc++.h>
using namespace std;

struct Node{ int data; Node* next; Node(int v){data=v;next=NULL;} };

Node* reverse(Node* head){
    Node* prev=NULL; Node* cur=head;
    while(cur){ Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    return prev;
}

int main(){
    vector<int> v={1,2,3,4};
    Node* head=NULL; Node* tail=NULL;
    for(int x:v){ Node* n=new Node(x); if(!head) head=tail=n; else{ tail->next=n; tail=n; } }
    head=reverse(head);
    while(head){ cout<<head->data; if(head->next) cout<<"->"; head=head->next; }
    cout<<"->NULL";
}
