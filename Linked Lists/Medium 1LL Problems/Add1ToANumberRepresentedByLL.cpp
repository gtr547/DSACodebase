// Given the head of a singly linked list representing a positive integer number. 
// Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. 
// The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

// The number will contain no leading zeroes except when the value represented is zero itself.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node( int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* toLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node( arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// reverse the linked list
Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = nullptr;

    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// naive approach       T.C - O(2N)         S.C - O(1)
Node* addOne(Node* head){
    head = reverse(head);

    Node* temp = head;
    int carry  =  1;

    while (temp)
    {
        temp->data = temp->data + carry;

        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }

        temp =  temp->next;
    }

    if(carry == 1){
        Node* newHead = new Node(1);
        head = reverse(head);
        newHead->next = head;
        return newHead;
    }
    head = reverse(head);
    
    return(head);
    
}

int main() {
    // Write your code here
    vector<int> arr;

    int n = 0;

    while(true){
        cin>>n;

        if(n == -1) break;

        arr.push_back(n);
    }

    Node* head = toLL(arr);

    head = addOne(head);

    print(head);
    

    return 0;
}