// Given two linked list, create a "Y" shaped singly linked list.

// "Y" shaped linked list are created when two linked list get merged such that they share a common tail (while having two different heads).


#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

// convert to linked list
Node* toLL(vector<int>& arr){
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

    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void createY(Node* head1, Node* head2, int mergePoint){
    Node* temp = head1;
    
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node* tail1 = temp;

    temp = head2;

    int cnt = 0;
    while(temp != nullptr){
        if(cnt == mergePoint){
            tail1->next = temp;
            break;
        }
        cnt++;
        temp = temp->next;
    } 
}

int main() {
    // Write your code here
    vector<int> arr1;
    vector<int> arr2;

    int n = 0;

    while (true)
    {
        cin>>n;

        if (n == -1)
        {
            break;
        }
        arr1.push_back(n);  
    }

    n = 0;

    while (true)
    {
        cin>>n;

        if (n == -1)
        {
            break;
        }
        arr2.push_back(n);  
    }

    int k = 0;
    cin>>k;


    Node* head1 = toLL(arr1);
    Node* head2 = toLL(arr2);

    createY(head1, head2, k);

    cout<<"list1: ";
    print(head1);
    cout<<endl;

    cout<<"list2: ";
    print(head2);
    cout<<endl;

    return 0;
}