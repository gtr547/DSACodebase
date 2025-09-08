// Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, topIndex, and size.

#include <bits/stdc++.h>
using namespace std;

class StImpl {
    public:
    int topIndex = -1;

    // the size of this array must be pre-provided
    int st[10];

    void push(int x){
        if(topIndex>10){
            cout<<"STACK OVERFLOW!";
            return;
        }
        topIndex = topIndex + 1;
        st[topIndex] = x;
    }

    void pop(){
        if(topIndex == -1){
            cout<<"STACK UNDERFLOW!";
            return;
        }
        topIndex = topIndex - 1;
    }

    int top(){
        if(topIndex == -1){
            return -1;
        }
        else{
            return st[topIndex];
        }
            
    }

    int size(){
        return topIndex + 1;
    }

};


int main() {
    // Write your code here
    StImpl s;
    s.push(5);
    s.push(4);
    s.push(7);
    // cout<<s.size()<<" ";
    // cout<<s.top()<<" ";
    s.pop();
    // cout<<s.top()<<" ";
    s.pop();
    s.pop();
    // cout<<s.size();
    cout<<s.top();


    return 0;
}