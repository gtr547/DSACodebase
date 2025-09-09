// Implement a Last-In-First-Out (LIFO) stack using an linked list. The implemented stack should support the following operations: push, pop, topIndexIndex, and sizeCnt.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

class Stack {
    Node* topIndex;
    int sizeCnt;

    public:
        //constructor
        Stack(){
            topIndex = nullptr;
            sizeCnt = 0;
        }

        //destructor
        ~Stack(){
            while (topIndex != nullptr)
            {
                pop();
            }
        }

        void push(int x){
            Node* temp = new Node(x);
            temp->next = topIndex;
            topIndex = temp;
            sizeCnt += 1;
        }

        void pop(){
            if (topIndex == nullptr) {
                cout << "Stack underflow! Cannot pop from empty stack" << endl;
                exit(1);
            }
            Node* temp = topIndex;
            topIndex = temp->next;
            delete temp;
            sizeCnt -= 1;
        }

        int top(){
            if(topIndex == nullptr){
                cout<<"Stack is Empty! No topIndex elements"<<endl;
                exit(1);
            }
            return topIndex->data;
        }

        int size(){
            return sizeCnt;
        }
};

int main() {
    // Write your code here

    Stack s;

    s.push(4);
    s.push(3);
    s.push(2);
    cout<<"The size of the stack is "<<s.size()<<endl;
    cout<<"The top of the stack is "<<s.top()<<endl;
    s.pop();
    cout<<"The top of the stack is "<<s.top()<<endl;
    cout<<"The size of the stack is "<<s.size()<<endl;

    return 0;
}