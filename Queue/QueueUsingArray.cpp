// Implement a First-In-First-Out (FIFO) Queue using an array. The implemented Queue should support the following operations: push, pop, top, and size.

#include <bits/stdc++.h>
using namespace std;

class Queue {
    public:
    
    int start = -1, end = -1, n = 10, currSize = 0;

    // the size of this array must be pre-provided
    int q[10];

    void push(int x){
        if (currSize == n)
        {
            cout<<"QUEUE IS FULL!";
            return;
        }

        if(currSize == 0){
            start = 0, end = 0;
        }
        else
        {
            end = (end + 1) % n;
        }

        q[end] = x;
        currSize += 1;
    }

    int pop(){
        if (currSize == 0)
        {
            cout<<"EMPTY QUEUE!";
            return 0;
        }
        
        int elm = q[start];

        if (currSize == 1)
        {
            start = end = -1;
        }
        else
        {
            start = (start + 1) % n;
        }
        currSize -= 1;
        return elm;    
    }

    int top(){
        if (currSize == 0)
        {
            return -1;
        }
        else
        {
            return q[start];
        }
    }

    int size(){
        return currSize;
    }

};


int main() {
    // Write your code here
    Queue q;

    q.push(2);
    q.push(5);
    q.push(3);
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
    

    return 0;
}