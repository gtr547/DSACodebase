// Given the head of two sorted linked lists consisting of nodes respectively. Merge both lists and return the head of the sorted merged list.

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

// print linked list
void print(Node* head){
    Node* temp = head;

    while (temp)
    {
       cout<<temp->data<<" ";
       temp = temp->next;
    }
    
}

// naive approach       T.C - O((n1 + n2) * log(n1 + n2))       S.C - O(n1 + n2)
// Node* merge(Node* head1, Node* head2){
//     vector<int> arr;

//     Node* temp = head1;

//     while(temp != nullptr){
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     temp = head2;
//     while(temp != nullptr){
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     sort(arr.begin(), arr.end());

//     Node* newHead = arrayToLL(arr);

//     return newHead;
// }


// optimal approach - using dummy node      T.C - O(n + m)      S.C - O(1)
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

    return dNode->next;
}


int main() {
    // Write your code here
    vector<int> arr1;
    vector<int> arr2;

    int x = 0;

    while (true)
    {
        cin>>x;

        if(x != -1){
            arr1.push_back(x);
        }
        else break;
    }

    x = 0;

    while (true)
    {
        cin>>x;

        if(x != -1){
            arr2.push_back(x);
        }
        else break;
    }
    
    Node* head1 = arrayToLL(arr1);
    Node* head2 = arrayToLL(arr2);

    Node* head = merge(head1, head2);
    print(head);

    return 0;
}