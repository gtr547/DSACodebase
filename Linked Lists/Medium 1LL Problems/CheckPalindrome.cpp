// Given the head of a singly linked list, return true if it palindrome is a or false otherwise.

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

// Naive approach   T.C - O(2N)  S.C - O(N)
bool isPalindrome(Node* head){
    stack<int> st;

    Node* temp = head;

    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr || !st.empty())
    {
        if(temp->data == st.top()){
            st.pop();
            temp = temp->next;
            continue;
        }
        else
            return false;
    }
    return true;    
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

    isPalindrome(head)? cout<<"Palindrome" : cout<<"Non Palindrome"; 
    
    
    return 0;
}