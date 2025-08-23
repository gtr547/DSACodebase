// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

//     For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// the naive approach to this problem consists of Hashing(map).

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

// print the linked list
void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// naive approach       T.C - O(N + N/2)     S.C - O(1)
Node* deleteMid(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    int n = 0;
    Node* temp = head;

    while (temp)
    {
        n++;
        temp = temp->next;
    }

    int res = (n/2);

    temp = head;

    while (temp)
    {
        res--;
        if(res == 0){
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
        
        temp = temp->next;
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
    print(head);

    cout<<endl;
    
    head = deleteMid(head);
    print(head);
    
    return 0;
}