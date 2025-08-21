// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.


#include <bits/stdc++.h>
using namespace std;

struct Node{
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

Node* toLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// print linked list
void print(Node* head){
    Node* temp = head;
    
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


// naive approach
Node* oddEven(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    
    vector<int> arr;

    Node* temp = head;

    // for odd indexed elements
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp) arr.push_back(temp->data); 

    temp = head->next;

    // for even indexed elements
    while (temp != nullptr && temp->next != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp) arr.push_back(temp->data); 

    temp = head;
    int i = 0;

    while (temp != nullptr && i<arr.size())
    {
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }

    return head;
      
}


int main() {
    // Write your code here
    vector<int> arr;
    
    int n = 0;

    while (true)
    {
        cin>>n;

        if(n != -1){
            arr.push_back(n);
        }
        else break;
    }
    
    Node* head = toLL(arr);

    head = oddEven(head);
    print(head);
    
    
    return 0;
}