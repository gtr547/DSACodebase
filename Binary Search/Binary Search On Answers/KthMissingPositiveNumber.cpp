// You are given a strictly increasing array ‘vec’ and a positive integer 'k'. 
// Find the 'kth' positive integer missing from 'vec'.

#include <bits/stdc++.h>
using namespace std;

// naive approcach 
// int findK(vector<int>& arr, int k, int n){
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i]<=k) k++;
//         else break;
//     }
//     return k;
// }

// optimal approach 
int findK(vector<int>& arr, int k, int n){
    int low = 0, high = n - 1;
   
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }

    return (low + k);
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
    
    cout<<findK(arr, k, arr.size());

    return 0;
}