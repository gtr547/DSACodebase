// Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.
// Note: Consider 0 based indexing

#include <bits/stdc++.h>
using namespace std;


// simple approach using linear search O(n)
// pair<int,int> ls(vector<int>& arr, int k){
//     int n = arr.size();
//     int first = -1, last = -1;
    
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == k)
//         {
//             if (first == -1){
//                 first = i;
//             } 
//             last = i;  
//         }
        
//     }
//     return make_pair(first, last);
// }


// optimal approach using binary search (with lower_bound and upper_bound concept - O(2*log n))
// int lowerBound(vector<int>& arr, int k){
//     int n = arr.size();
//     int low = 0, high = n-1;
//     int ans = n;

//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;

//         if (arr[mid] >= k)
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
        
//     }
//     return ans;
// }

// int upperBound(vector<int>& arr, int k){
//     int n = arr.size();
//     int low = 0, high = n-1;
//     int ans = n;

//     while(low <= high){
//         int mid = low + (high - low) / 2;

//         if(arr[mid] > k){
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
        
//     }
//     return ans;

// }

// pair<int,int> findFirstAndLastOccurrance(vector<int>& arr, int k){
//     int n = arr.size();
//     int lb = lowerBound(arr, k);
    
//     if(lb == n || arr[lb] != k) return {-1, -1};
//     return{lb, upperBound(arr, k) - 1};
    
// }


// optimal solution using binary search (without lower_bound and upper_bound)
int first(vector<int>& arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    int fst = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            fst = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        
    }
    return fst;
}

int last(vector<int>& arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    int lst = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            lst = mid;
            low = mid + 1;
        }
        else if(arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        
        
    }
    return lst;
}

pair<int, int> findFirstAndLastOccurrance(vector<int>& arr, int k){
    int firstOcc = first(arr, k);
    if (firstOcc == -1) return {-1, -1};
    
    return {firstOcc, last(arr, k)};
    
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
    
    
    pair<int, int> ans = findFirstAndLastOccurrance(arr, k);

    cout<<"["<<ans.first<<" "<<ans.second<<"]";
    
    return 0;
}