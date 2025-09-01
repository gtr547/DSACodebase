// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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

// T.C - O(max(m, n))       S.C - O(max(m, n)), where 'm' and 'n' are the lenght of both the linked list respectively
Node* addTwoNo(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;

    Node* dNode = new Node(-1);
    Node* curr = dNode;

    int carry = 0;

    while(t1 || t2){
        int sum = carry;

        if(t1) sum += t1->data;
        if(t2) sum += t2->data;

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = newNode;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    Node* head = dNode->next;
    delete dNode;

    return head;

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

    Node* sumHead = addTwoNo(head1, head2);

    print(sumHead);

    return 0;
}