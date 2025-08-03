// You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. 
// Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, 
// the sum of the division's result is less than or equal to the given threshold value.

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int mid, int k){
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (arr[i] + mid - 1) / mid;

    }
    if (sum <= k) return true;
    else return false;  
}

int findDiv(vector<int>& arr, int k){
    int n = arr.size();
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, mid, k) == 1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        
    }
    return low;
    
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
    
    cout<<findDiv(arr, k);
    

    return 0;
}