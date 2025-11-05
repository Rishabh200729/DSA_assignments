#include <bits/stdc++.h>
using namespace std;

struct Node{ int data; Node* next; Node(int v){data=v;next=NULL;} };

int middle(Node* head){
    Node* slow=head; Node* fast=head;
    while(fast && fast->next){ slow=slow->next; fast=fast->next->next; }
    return slow->data;
}

int main(){
    vector<int> v={1,2,3,4,5};
    Node* head=NULL; Node* tail=NULL;
    for(int x:v){ Node* n=new Node(x); if(!head) head=tail=n; else{ tail->next=n; tail=n; } }
    cout<<middle(head)<<endl;
}
