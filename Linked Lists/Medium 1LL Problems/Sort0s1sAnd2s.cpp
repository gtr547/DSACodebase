// Given a linked list containing only 0s, 1s and 2s. Sort the linked list in ascending manner, and return the head;

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node( int data1, Node* next1){
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

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node( arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


// naive approach       T.C - O(2N)        S.C - O(1)
// Node* sort(Node* head){
//     Node* temp = head;
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0;

//     while(temp != nullptr){
//         if(temp->data == 0) cnt0++;
//         else if(temp->data == 1) cnt1++;
//         else cnt2++;

//         temp = temp->next; 
//     }

//     temp = head;

//     while(temp != nullptr){
//         if(cnt0){
//             temp->data = 0;
//             cnt0--;
//         }
//         else if(cnt1){
//             temp->data = 1;
//             cnt1--;
//         }
//         else{
//             temp->data = 2;
//             cnt2--;
//         }
        
//         temp = temp->next;
//     }

//     return head;
// }


// optimal approach         T.C - O(N)      S.C - O(1)
Node* sort(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    // dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zero = zeroHead;

    Node* oneHead = new Node(-1);
    Node* one = oneHead;

    Node* twoHead = new Node(-1);
    Node* two = twoHead;

    // traversing the linked list
    Node* temp = head;

    while(temp != nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }

        temp = temp->next;
    }

    zero->next = (oneHead->next)? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    head = zeroHead->next;
    
    // cleaning the memory
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main() {
    // Write your code here
    vector<int> arr;

    int n = 0;

    while(true){
        cin>>n;

        if(n == -1) break;

        arr.push_back(n);
    }

    Node* head = toLL(arr);

    // print(head);
    // cout<<endl;
    
    head = sort(head);

    print(head);

    return 0;
}