//  Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

#include <bits/stdc++.h>
using namespace std;

// Brute force approach (tripple loop)
// int length(vector<int> arr, int k){
//     int n = arr.size();
//     int maxLen = 0;

//     // iterates over all possible starting indices of subarrays
//     for (int i = 0; i < n; i++)
//     {

//         // iterates over all possible ending indices of subarrays
//         for (int j = i; j < n; j++)
//         {   
//             int sum = 0;
            
//             // calculate the sum of the subarray (arr[i....j]) by iterating from i to j
//             for (int x = i; x <= j; x++)
//             {
//                 sum += arr[x];
//             }

//             // if computed 'sum == k', then update the 'maxLen' with maximum of 'maxLen' and the length of the current subarray 'j-i+1'
//             if (sum == k)
//             {
//                 maxLen = max(maxLen, j-i+1);
//             }
//         }
//     }

//     return maxLen; 
// }

// optimized brute force T.c -> O(n^2) 
// int length(vector<int> arr, int k){
//     int n = arr.size();
//     int maxLen = 0;

//     // iterates over all possible starting indices of subarrays
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;

//         // iterates over all possible ending indices of subarrays
//         for (int j = i; j < n; j++)
//         {   

//             // adds the sum with that elem
//             sum += arr[j];
            
//             // update maxLen
//             if (sum == k)
//             {
//                 maxLen = max(maxLen, j-i+1);
//             }
//         }
//     }

//     return maxLen; 
// }

// Better Solution using PrefixSum and Hashing (This approach is optimal if the input array contains -ve integers)
// int length(vector<int> arr, long long k){
//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         sum += arr[i];
//         if (sum == k)
//         {
//             maxLen = max(maxLen, i+1);
//         }

//         long long rem = sum - k;
//         if (preSumMap.find(rem)!= preSumMap.end())
//         {
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
     
//         if (preSumMap.find(sum)==preSumMap.end())
//         {
//             preSumMap[sum] = i;
//         }
        
//     }   
//     return maxLen;
// }


// Optimal Solution (for non arrays with positive integers)
int length(vector<int> arr, long long k){
    // using two pointers
    int l = 0, r = 0;

    long long sum = arr[0];
    int maxLen = 0;
    while (r < arr.size())
    {
        if (l<=r && sum>k)
        {
            sum -= arr[l];
            l++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, r - l + 1);

        }
        r++;
        if (r<arr.size())
        {
            sum += arr[r];
        }
        
    }
    
    return maxLen;
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

    long long k;
    cin>>k;

    cout<<length(arr, k);
        

    return 0;
}