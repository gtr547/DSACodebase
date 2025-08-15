//  Given the head of a linked list of integers, determine the middle node of the linked list. 
// However, if the linked list has an even number of nodes, return the second middle node. 

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

// naive approach - T.C -> O(N + N/2), S.C -> O(1)
Node* findMid(Node* head){
    Node* temp = head;
    int cnt  = 0;

    while(temp!= NULL){
        cnt ++;
        temp = temp->next;
    }
    
    int mid = (cnt / 2) + 1;

    temp = head;
    while (temp != NULL)
    {
        mid--;
        if(mid == 0) break;
        temp = temp->next;
    }
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

    head = findMid(head);
    cout<<head->data;
    
    return 0;
}