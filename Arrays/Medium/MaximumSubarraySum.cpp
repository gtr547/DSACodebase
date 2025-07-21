// Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.

#include <bits/stdc++.h>
using namespace std;

// bruteforce approach 
// int maxSum(vector<int> &arr){
//     int n = arr.size();
//     int maxi = INT_MIN;

//     for (int i = 0; i < n; i++)
//     {
//         for(int j = i; j < n; j++){
//             int sum = 0;
//             for (int k = i; k < j; k++)
//             {
//                 sum += arr[k];
//             }

//             maxi = max(sum, maxi);
            
//         }
//     }

//     return maxi;
    
// }


// better approach (omitting the innermost loop)
// int maxSum(vector<int> &arr){
//     int n = arr.size();
//     int maxi = INT_MIN;

//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for(int j = i; j < n; j++){
            
//             sum += arr[j];
//             maxi = max(sum, maxi);
            
//         }
//     }

//     return maxi;
    
// }

// optimal approach using kadane's algorithm
int maxSum(vector<int> &arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;

    // to get the subarray with maximum sum  
    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0 ) start = i; // to get the subarray with maximum sum  

        
        sum += arr[i];
        
        if(sum > maxi){
            maxi = sum;
            ansStart = start, ansEnd = i; // to get the subarray with maximum sum  
        }

        if (sum < 0)
        {
            sum = 0;
        }
        
    }

    if (maxi < 0)
    {
        maxi = 0;
    }
    

    return maxi;
    
}


int main() {
    // Write your code here
    vector<int> arr;
    
    string line;

    getline(cin, line);

    stringstream ss(line);
    int n = 0;
    while (ss >> n)
    {
        arr.push_back(n);
    }

   cout<<" "<<maxSum(arr);

    return 0;
}