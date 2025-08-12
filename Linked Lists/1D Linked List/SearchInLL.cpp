// Given the head of a linked list and a element find if the element exist in the linked list or not.
// return true if it is present in the Search space and if it's not return false. 

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

// implementing the linked list 
Node* arrayToLL(vector<int>& arr){
    

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
    
}

// searching in a linked list
bool isPresent(Node* head, int k){
    Node* temp = head;
    while (temp != nullptr)
    {
        if (temp->data == k)
        {
            return true;
        }
        
        temp = temp->next;
    }

    return false;
    
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
    
    Node* head = arrayToLL(arr);

    int k = 0;
    cin>>k;
   
    isPresent(head, k)? cout<<"Present" : cout<<"Not Present";

    return 0;
}