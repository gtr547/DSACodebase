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

// print linked list
void print(Node* head){
    Node* temp = head;

    while (temp)
    {
       cout<<temp->data<<" ";
       temp = temp->next;
    }
    
}

// Constructing a linked list
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

// Deleting the head of a linked list
Node* delHead(Node* head){
    // edge case (in case the list is empty)
    if (head == NULL) return head;
    
    // store the original head, so that we can free memory safely;
    Node* temp = head;

    // move the head to the new head 
    head = temp->next;

    // delete the previous head(to free up the memory space)
    delete temp;

    // return the new head
    return head;
    
}

// Deleting the tail of a linked list 
Node* delTail(Node* head){
    // Edge case( if the list is empty or has only one element)
    if(head == NULL || head->next == NULL) return NULL;

    // store the original head, so that we can free memory safely;
    Node* temp = head;

    // traverse untill we are at the n-2 node
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // delete the tail and asiign null pointer to n-2th element
    delete temp->next;
    temp->next = nullptr;
    
    // return head
    return head;
}

// Deleting the kth element in a linked list
Node* delKth(Node* head, int k){
    // edge case (if the list is empty)
    if(head == NULL) return head;

    // if deleting the first element
    if(k == 1){
        Node* temp = head;

        head = head->next;

        delete temp;

        return head;
    }

    int cnt = 0;

    Node* prev = NULL;
    Node* temp = head;

    // traverse the entire list
    while (temp != NULL)
    {
        cnt++;

        if(cnt == k){
            // link the before element and the after element.
            prev->next = prev->next->next;
            // delete the current element
            delete temp;
            break;
        }
        // store the previous element
        prev = temp;
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

    int k = 0;
    cin>>k;
   
    print(head);
    cout<<endl;
    head = delKth(head, k);
    print(head);
    
    return 0;
}