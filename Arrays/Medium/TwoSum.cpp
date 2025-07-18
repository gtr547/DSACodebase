// Given an array of integers arr[] and an integer target.
// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
// 2nd variant: Return indices of the two numbers such that their sum is equal to the target.

#include <bits/stdc++.h>
using namespace std;

// brute approach
// bool twoSum(vector<int> arr, int k){
//     int n = arr.size();

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
            
//             if (arr[i] + arr[j] == k)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }


// Better approach using Hashing
// bool twoSum(vector<int> arr, int k){
//     int n = arr.size();
//     map<int, int> mpp;
    
//     for (int i = 0; i < n; i++)
//     {
//         int a = arr[i];
//         int rem = k - a;

//         if(mpp.find(rem)!= mpp.end()){
//             return true; // return {mpp[rem], i} if wanted indices.
//         }
//         mpp[a] = i;
//     }
    
//     return false; // return {-1, -1} if asked for indices.

// }


// Optimal approach (using two pointers, only for the first varient) 
bool twoSum(vector<int> arr, int k){
    int n = arr.size();
    int left = 0, right = n-1;
    sort(arr.begin(), arr.end());

    while(left<right){
        int sum = arr[left] + arr[right];
        
        if (sum < k )
        {
            left ++;
            continue;
        }

        else if (sum > k)
        {
            right --;
            continue;
        }

        else return true;
    }

    return false;

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

    int k;
    cin>>k;

    twoSum(arr, k) ? cout <<"YES" : cout <<"No";

    return 0;
}