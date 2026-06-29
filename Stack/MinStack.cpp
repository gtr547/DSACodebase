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
// class Stack {
//     stack <pair<int, int>> st;

//     public:
//         void push(int x){
//             if(st.empty()){
//                 st.push({x, x});
//             }
//             else{
//                 st.push({x, min(x, st.top().second)});
//             }
//         }

//         void pop(){
//             st.pop();
//         }

//         int top(){
//             return st.top().first;
//         }

//         int getMin(){
//             return st.top().second;
//         }

// };

// optimized approach
class Stack {
    stack <long long> st;
    long long min = INT_MAX;

    public:
        void push(int val){
            if(st.empty()){
                st.push(val);
                min = val;
            }
            else{
                if(val >= min) st.push(val);
                else {
                    st.push(2LL * val - min);
                    min = val;
                }
            }
        }

        void pop(){
            if(st.empty()) return;
            long long x = st.top();
            st.pop();

            if(x < min) min = 2LL * min - x;
        }

        int top(){
            if(st.empty()) return -1;
            long long x = st.top();

            if( x < min) return min;
            return x;
        }

        int getMin(){
            return min;
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