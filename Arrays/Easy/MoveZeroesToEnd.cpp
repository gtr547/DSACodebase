// Given an array of positive integers, move all the zeroes in the array to the end of the array and move all the non negative integer to the front by maintianing order.

#include <bits/stdc++.h>
using namespace std;

// brute force approach
// void MoveZeroes(vector<int>& arr){
//     vector<int> temp;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         if(arr[i]!=0){
//             temp.push_back(arr[i]);
//         }
//     }

//     for (int i = 0; i < temp.size(); i++)
//     {
//          arr[i] = temp[i];
//     }

//     for (int i = temp.size(); i < arr.size(); i++)
//     {
//         arr[i] = 0;
//     }
    
    
    
// }

// Optimal Approach (two pointers)
void MoveZeroes(vector<int>& arr){
    int j = -1;

    // finding the index of the first occurrance 0, 
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==0)
        {
            j=i; // j points to the index first occurrance of 0
            break;
        }
        
    }

    if(j==-1) return;

    // starting a loop from j+1, and checking each element, if its non zero then, swap its element with j 
    for (int i = j+1; i < arr.size(); i++)
    {
        if (arr[i]!=0)
        {
            //swapping arr[i] and arr[j]
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

            j++;
        }
        
    }
    
    
    
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


    MoveZeroes(arr);
    

    for (int i = 0; i <= arr.size()-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}