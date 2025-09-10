// Implement a first-in-first-out (FIFO) queue using stack. The implemented queue should support all the functions of a normal queue (push, top, pop, and size).

#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;
    public:
        void push(int x) {
            while (s1.size()){
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(x);

            while(s2.size()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        int pop() {
            int elm = s1.top();
            s1.pop();
            return elm;
        }
        
        int peek() {
            return s1.top();
        }
        
        int size(){
            return s1.size();
        }
};

int main() {
    // Write your code here
    Queue q;

    q.push(1);
    q.push(2);
    q.push(4);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;

    return 0;
}