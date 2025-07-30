// Given a sorted array of N integers and an integer k, write a program to find the upper bound of k.

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] > k){
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
    
    int k = 0;
    cin>>k;
    
    cout<<"The upper bound of "<<k<<" is "<<upperBound(arr, k);
   

    return 0;
}