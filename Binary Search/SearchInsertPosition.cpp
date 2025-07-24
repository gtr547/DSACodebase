// You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
// If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.


#include <bits/stdc++.h>
using namespace std;

// we can solve this problem using lower bound (note: the solution of this problem is same as the lower bound problem) 
int insertPos(vector<int>& arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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
    
    int x = 0;
    cin>>x;
    
    cout<<" "<<insertPos(arr, x);
   

    return 0;
}