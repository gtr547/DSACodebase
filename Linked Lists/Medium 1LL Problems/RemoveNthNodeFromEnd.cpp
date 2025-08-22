// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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

// naive approach   T.c - O(2N)     S.C - O(1)
Node* removeN(Node* head, int n){
    // get the length of the liked list
    int cnt = 0;
    Node* temp = head;
    
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }

    if(n == cnt ){
        Node* newHead = head->next;
        free(head);
        return newHead;
    }

    int res = cnt - n;

    temp = head;

    while(temp != nullptr){
        res--;
        if(res == 0){
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        }
        temp = temp->next;
    }
    return head;
}


int main() {
    // Write your code here
    vector<int> arr;
    
    int x = 0;

    while (true)
    {
        cin>>x;

        if(x != -1){
            arr.push_back(x);
        }
        else break;
    }
    
    Node* head = arrayToLL(arr);

    int n = 0;
    cin>>n;

    print(head);
    cout<<endl;
   
    head = removeN(head, n);
    print(head);

    return 0;
}