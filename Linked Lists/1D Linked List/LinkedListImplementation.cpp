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


Node* convertToLL(vector<int> &arr){

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



int main() {
    // Write your code here
    vector<int> arr = {2,5,8,7,10,13,15};

    Node* head = convertToLL(arr);

    cout<<head->data<<endl;

    // linked list traversal

    Node* temp = head;
    
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    

    return 0;
}