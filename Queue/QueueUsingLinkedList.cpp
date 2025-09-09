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

class Queue {
    Node* start;
    Node* end;
    int sizeCnt;
    

    public:
        // constructor
        Queue(){
            start = nullptr;
            end = nullptr;
            sizeCnt = 0;
        }

        // destructor
        ~Queue(){
            while (start != nullptr)
            {
                pop();
            }
        }


        void push(int x){
            Node* temp = new Node(x);
            if(start == nullptr && end == nullptr){
                start = temp;
                end  = temp;
                sizeCnt = 1;
            }
            else
            {
                end->next = temp;
                end = temp;
                sizeCnt += 1;
            }
            
        }

        void pop(){
            if(start == nullptr){
                cout<<"Queue is Empty!"<<endl;
                exit(1);
            }
            Node* temp = start;
            start = temp->next;
            delete temp;
            sizeCnt -= 1;
        }

        int top(){
            if(start == nullptr){
                cout<<"Queue is Empty! No elem on top."<<endl;
                exit(1);
            }
            return start->data;
        }

        int size(){
            return sizeCnt;
        }
};

int main() {
    // Write your code here

    Queue q;

    q.push(7);
    q.push(2);
    q.push(3);
    q.push(5);
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    q.pop();
    cout<<q.top()<<endl;

    return 0;
}