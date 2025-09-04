#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack(){top=-1;}
    bool isEmpty(){return top==-1;}
    bool isFull(){return top==MAX-1;}
    void push(int x){if(!isFull()) arr[++top]=x;}
    int pop(){if(!isEmpty()) return arr[top--]; return -1;}
    int peek(){if(!isEmpty()) return arr[top]; return -1;}
    void display(){for(int i=0;i<=top;i++) cout<<arr[i]<<" "; cout<<"\n";}
};

class CharStack {
    char arr[MAX];
    int top;
public:
    CharStack(){top=-1;}
    bool isEmpty(){return top==-1;}
    bool isFull(){return top==MAX-1;}
    void push(char x){if(!isFull()) arr[++top]=x;}
    char pop(){if(!isEmpty()) return arr[top--]; return '\0';}
    char peek(){if(!isEmpty()) return arr[top]; return '\0';}
};

void reverseString(char s[]) {
    CharStack st;
    for(int i=0;s[i];i++) st.push(s[i]);
    while(!st.isEmpty()) cout<<st.pop();
    cout<<"\n";
}

bool balanced(char s[]) {
    CharStack st;
    for(int i=0;s[i];i++){
        char c=s[i];
        if(c=='('||c=='['||c=='{') st.push(c);
        else if(c==')'||c==']'||c=='}'){
            if(st.isEmpty()) return false;
            char t=st.pop();
            if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{')) return false;
        }
    }
    return st.isEmpty();
}

int prec(char c) {
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return -1;
}

void infixToPostfix(char infix[], char postfix[]) {
    CharStack st; int k=0;
    for(int i=0;infix[i];i++){
        char c=infix[i];
        if(isalnum(c)) postfix[k++]=c;
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.isEmpty() && st.peek()!='(') postfix[k++]=st.pop();
            st.pop();
        } else {
            while(!st.isEmpty() && prec(st.peek())>=prec(c)) postfix[k++]=st.pop();
            st.push(c);
        }
    }
    while(!st.isEmpty()) postfix[k++]=st.pop();
    postfix[k]='\0';
}

int evalPostfix(char postfix[]) {
    Stack st;
    for(int i=0;postfix[i];i++){
        char c=postfix[i];
        if(isdigit(c)) st.push(c-'0');
        else {
            int v2=st.pop(), v1=st.pop();
            switch(c) {
                case '+': st.push(v1+v2); break;
                case '-': st.push(v1-v2); break;
                case '*': st.push(v1*v2); break;
                case '/': st.push(v1/v2); break;
                case '^': st.push(pow(v1,v2)); break;
            }
        }
    }
    return st.pop();
}

int main() {
    int ch; Stack s;
    while(true){
        cout<<"1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.ReverseString 8.Balanced 9.InfixToPostfix 10.EvalPostfix 11.Exit\n";
        cin>>ch;
        if(ch==1){int x;cin>>x;s.push(x);}
        else if(ch==2) cout<<s.pop()<<"\n";
        else if(ch==3) cout<<(s.isEmpty()?"Yes":"No")<<"\n";
        else if(ch==4) cout<<(s.isFull()?"Yes":"No")<<"\n";
        else if(ch==5) s.display();
        else if(ch==6) cout<<s.peek()<<"\n";
        else if(ch==7){char str[100];cin>>str;reverseString(str);}
        else if(ch==8){char str[100];cin>>str;cout<<(balanced(str)?"Balanced":"Not Balanced")<<"\n";}
        else if(ch==9){char infix[100],postfix[100];cin>>infix;infixToPostfix(infix,postfix);cout<<postfix<<"\n";}
        else if(ch==10){char postfix[100];cin>>postfix;cout<<evalPostfix(postfix)<<"\n";}
        else break;
    }
}
