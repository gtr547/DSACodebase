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

// print linked list
void print(Node* head){
    Node* temp = head;

    while (temp)
    {
       cout<<temp->data<<" ";
       temp = temp->next;
    }
    
}

// Constructing a linked list
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

// inserting at the head of the linked list
Node* insertHead(Node* head, int el){

    Node* temp = new Node(el);
    temp->next = head;
    return temp;
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

    // int k = 0;
    // cin>>k;
    
    int el;
    cin>>el;

    print(head);
    cout<<endl;
    head = insertHead(head, el);
    print(head);
    
    
    return 0;
}