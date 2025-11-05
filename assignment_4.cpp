#include <bits/stdc++.h>
using namespace std;

#define MAX 100

// 1) Simple Queue
class SimpleQueue {
    int arr[MAX];
    int front, rear;
public:
    SimpleQueue() { front = -1; rear = -1; }
    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == MAX - 1; }
    void enqueue(int x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (isEmpty()) return;
        front++;
    }
    void display() {
        if (isEmpty()) return;
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
    void peek() {
        if (isEmpty()) return;
        cout << arr[front] << endl;
    }
};

// 2) Circular Queue
class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() { front = -1; rear = -1; }
    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1)); }
    void enqueue(int x) {
        if (isFull()) return;
        if (front == -1) front = rear = 0;
        else if (rear == MAX - 1 && front != 0) rear = 0;
        else rear++;
        arr[rear] = x;
    }
    void dequeue() {
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else if (front == MAX - 1) front = 0;
        else front++;
    }
    void display() {
        if (isEmpty()) return;
        if (rear >= front)
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        else {
            for (int i = front; i < MAX; i++) cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++) cout << arr[i] << " ";
        }
        cout << endl;
    }
    void peek() {
        if (isEmpty()) return;
        cout << arr[front] << endl;
    }
};

// 3) Interleave first half with second half
void interleave(queue<int> &q) {
    int n = q.size() / 2;
    queue<int> firstHalf;
    for (int i = 0; i < n; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

// 4) First non-repeating character
void firstNonRepeating(string s) {
    vector<int> freq(26, 0);
    queue<char> q;
    for (char c : s) {
        freq[c - 'a']++;
        q.push(c);
        while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

// 5a) Stack using two queues
class StackTwoQ {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (!q1.empty()) q1.pop();
    }
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    bool empty() { return q1.empty(); }
};

// 5b) Stack using one queue
class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    bool empty() { return q.empty(); }
};

int main() {
    // Example usage:
    SimpleQueue sq;
    sq.enqueue(1); sq.enqueue(2); sq.enqueue(3);
    sq.display(); sq.dequeue(); sq.display(); sq.peek();

    CircularQueue cq;
    cq.enqueue(10); cq.enqueue(20); cq.enqueue(30);
    cq.display(); cq.dequeue(); cq.display(); cq.peek();

    queue<int> q;
    vector<int> v = {4,7,11,20,5,9};
    for (int x : v) q.push(x);
    interleave(q);
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << endl;

    firstNonRepeating("aabc");

    StackTwoQ s2;
    s2.push(10); s2.push(20); s2.pop(); cout << s2.top() << endl;

    StackOneQ s1;
    s1.push(5); s1.push(6); s1.pop(); cout << s1.top() << endl;
}
