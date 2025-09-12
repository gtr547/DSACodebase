// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

//     MinStack() initializes the stack object.
//     void push(int val) pushes the element val onto the stack.
//     void pop() removes the element on the top of the stack.
//     int top() gets the top element of the stack.
//     int getMin() retrieves the minimum element in the stack.

// You must implement a solution with O(1) time complexity for each function.

#include <bits/stdc++.h>
using namespace std;

// better approach
class Stack {
    stack <pair<int, int>> st;

    public:
        void push(int x){
            if(st.empty()){
                st.push({x, x});
            }
            else{
                st.push({x, min(x, st.top().second)});
            }
        }

        void pop(){
            st.pop();
        }

        int top(){
            return st.top().first;
        }

        int getMin(){
            return st.top().second;
        }

};

int main() {
    // Write your code here
    Stack s;
    s.push(12);
    s.push(15);
    s.push(10);
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    return 0;
}