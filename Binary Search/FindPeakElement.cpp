// Given an array of length N. Peak element is defined as the element greater than both of its neighbors. 
// Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. 
// If there are multiple peak numbers, return the index of any peak number.

// Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, 
// the next element should be considered as negative infinity.


#include <bits/stdc++.h>
using namespace std;

// /naive solution using linear search
int findPeak(vector<int> &arr){
    int n = arr.size();

    for(int i = 0; i<n; i++){
        if ((i==0 || arr[i-1] < arr[i]) &&(i == n-1 || arr[i] > arr[i+1]))
        {
            return i;
        }
    }
    return -1;
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
    
    cout<<findPeak(arr);

    return 0;
}