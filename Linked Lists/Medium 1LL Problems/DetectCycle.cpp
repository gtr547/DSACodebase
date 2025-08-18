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

// creating cycles in a linked list
Node* createCycle(Node* head, int k){
    if(head == nullptr || k <= 0) return head;

    Node* tail = head;
    Node* cycleNode = nullptr;
    int index = 1;

    while(tail->next  != nullptr){
        if(index == k){
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }

    if(index == k){
        cycleNode = tail;
    }

    if(cycleNode != nullptr){
        tail->next = cycleNode;
    }

    return head;
}

// optimal solution to detect cycle in a linked list using Flyods cycle detection algorithm aka Tortoise and hare algorithm
bool hasCycle(Node* head){
    if(head == nullptr || head->next == nullptr){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
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
    
    Node* head = toLL(arr);

    int k;
    cin>>k;

    head = createCycle(head, k);

    hasCycle(head)? cout<<"has cycle" : cout<<"doesn't has cycle";
    
    return 0;
}