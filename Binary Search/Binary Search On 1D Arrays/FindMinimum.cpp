// Given an integer array arr of size N, sorted in ascending order (with distinct values). 
// Now the array is rotated between 1 to N times which is unknown. 
// Find the minimum element in the array.

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = INT_MAX;

    while ( low <= high)
    {
        int mid = low + (high - low) / 2;

        // left half is sorted.
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }

        // right half is sorted
        else
        {
        
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }

    }
    return ans;


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
    
    cout<<findMin(arr);
    
    return 0;
}