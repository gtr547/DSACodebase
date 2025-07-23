// You are given a sorted array of integers and a target, your task is to search for the target in the given array. 
// Assume the given array does not contain any duplicate numbers.

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == k) return mid;

        else if(k > arr[mid]) low = mid + 1;

        else high = mid - 1;
        
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
    
    int k = 0;
    cin>>k;
    
    cout<<"Item found at index "<<binarySearch(arr, k);

    return 0;
}