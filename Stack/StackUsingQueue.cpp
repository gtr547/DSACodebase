// Implement a last-in-first-out (LIFO) stack using queue. The implemented stack should support all the functions of a normal stack (push, top, pop, and size).

#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue <int> q;

    public:
        void push(int x){
            int s = q.size();

            q.push(x);

            for(int i = 0; i < s; i++){
                q.push(q.front());
                q.pop();
            }
        }

        int pop(){
            int elem = q.front();
            q.pop();
            return elem;
        }

        int top(){
            return q.front();
        }

        int size(){
            return q.size();
        }

};

int main() {
    // Write your code here
    Stack s;

    s.push(1);
    s.push(2);
    s.push(4);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;

    return 0;
}