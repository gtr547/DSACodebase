// Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

#include <bits/stdc++.h>
using namespace std;


// Brute force approach
// void unionOfArrays(vector<int>& arr1, vector<int>& arr2){

//     set<int> uni;

//     for (int i = 0; i < arr1.size(); i++)
//     {
//         uni.insert(arr1[i]);
//     }

//     for (int  i = 0; i < arr2.size(); i++)
//     {
//         uni.insert(arr2[i]);
//     }

//     for (auto it = uni.begin(); it != uni.end(); it++)
//     {
//         cout<< *it <<" ";
//     }
     
// }

// optimal approach (using two pointers to iterate through each of the array)
void unionOfArrays(vector<int>& arr1, vector<int>& arr2){

    // initializing two pointers
    int i = 0, j = 0;
    list<int> uni;

    // iterating through the arrays 
    while (i < arr1.size() && j < arr2.size())
    {
        // if element in array 1 is smaller than the element in array 2
        if (arr1[i] < arr2[j])
        {
            // avoids adding duplicates to the uni list
            if ( uni.empty() || uni.back()!=arr1[i])
            {
                // adding the element in the list
                uni.push_back(arr1[i]);
            }
            // incrementing the pointer
            i++;
            
        }
        // if element in array 1 is larger than the element in array 2
        else if (arr1[i] > arr2[j])
        {
            if ( uni.empty() || uni.back()!=arr2[j])
            {
                // adds that element to the list
                uni.push_back(arr2[j]);
            }
            j++;
        }
        // if element in array 1 and element in array 2 are same 
        else 
        {
            if ( uni.empty() || uni.back()!=arr1[i])
            {
                // adding the element of array 1, can also take the array 2 element
                uni.push_back(arr1[i]);
            }
            // incrementing both the pointers
            i++;
            j++;
        }
    }

    // when one of the array 2 is fully iterated
    while (i < arr1.size())
    {
        if ( uni.empty() || uni.back()!=arr1[i])
            {
                uni.push_back(arr1[i]);
            }
        i++;
    }

    // when one of the array 1 is fully iterated
    while (j < arr2.size())
    {
        if ( uni.empty() || uni.back()!=arr2[j])
            {
                uni.push_back(arr2[j]);
            }
        j++;
    }
    
    for(auto it: uni){
        cout << it <<" ";
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

        if(n != -1){
            arr1.push_back(n);
        }
        else break;
    }

    n = 0;

    while (true)
    {
        cin>>n;
        
        if (n!=-1)
        {
            arr2.push_back(n);
        }
        else break;        
    }


    unionOfArrays(arr1, arr2);
    
    return 0;
}