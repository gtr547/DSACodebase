// Given an array(sorted) of integer, where every element except one wil be appearing twice number f times, Find the element that appears once.

#include <bits/stdc++.h>
using namespace std;

// optimal solution using binary search
int search(vector<int>& arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n-2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;


        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) low = mid + 1;
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
    
    cout<<search(arr);
    
    return 0;
}
