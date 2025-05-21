// Given an array of length N, rotate the array left by one place

#include <bits/stdc++.h>
using namespace std;

void rotateLeft(vector<int>& arr){

    // store the element at the 0th index in an temporary variable
    int n = arr.size(), temp = arr[0];

    // iterate through the array from the 1st index to the last 
    for (int i = 1; i < n; i++)
    {
        // store the value present in the current index in the previous index
        arr[i-1]=arr[i];
    }

    // append the temp in the end of the array
    arr[n-1]= temp;
    
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

    rotateLeft(arr);

    for (int i = 0; i <= arr.size()-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}