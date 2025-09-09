// Implement a First-In-First-Out (FIFO) Queue using an linked list. The implemented Queue should support the following operations: push, pop, topIndexIndex, and sizeCnt.

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
            if(start == nullptr){
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
                return;
            }
            Node* temp = start;
            start = temp->next;

            if(start == nullptr){
                end = nullptr;
            }

            delete temp;
            sizeCnt -= 1;
        }

        int top(){
            if(start == nullptr){
                cout<<"Queue is Empty! No elem on top."<<endl;
                return -1;
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