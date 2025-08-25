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
// Node* sort(Node* head){
//     vector<int> arr;

//     Node* temp = head;

//     while(temp != nullptr){
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     sort(arr.begin(), arr.end());

//     temp = head;
//     int i = 0;

//     while(temp != nullptr && i<arr.size()){
//         temp->data = arr[i];
//         temp = temp->next;
//         i++;
//     }

//     return head; 
// }

// getting the mid
Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// merging two sorted list
Node* merge(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dNode = new Node(-1);
    Node* temp = dNode;

    while (t1 != nullptr && t2 != nullptr)
    {
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1 != nullptr) temp->next = t1;
    else temp->next = t2;

    Node* head = dNode->next;
    dNode->next = nullptr;
    delete dNode;
    return head;
}

// optimal approach - using merge sort      T.C - O(N log N)        S.C - O(1)
Node* sort(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    // getting the mid
    Node* mid = getMid(head);
    
    Node* leftHead = head;
    Node* rightHead = mid->next;
    mid->next = nullptr;

    // recursively calling sort(basic merge sort implementation)
    leftHead = sort(leftHead);
    rightHead = sort(rightHead);

    // merging two sorted lists
    return merge(leftHead, rightHead);
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