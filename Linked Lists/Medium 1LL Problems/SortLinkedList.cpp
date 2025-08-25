// Given the head of a linked list, return the list after sorting it in ascending order.

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

void print(Node* head){
    Node* temp = head;

    while (temp)
    {
       cout<<temp->data<<" ";
       temp = temp->next;
    }
    
}

// naive approach       T.C - O(N log N)        S.C - O(N)
Node* sort(Node* head){
    vector<int> arr;

    Node* temp = head;

    while(temp != nullptr){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    temp = head;
    int i = 0;

    while(temp != nullptr && i<arr.size()){
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

    head = sort(head);
    print(head);
    
    return 0;
}