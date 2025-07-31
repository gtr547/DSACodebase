// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

#include <bits/stdc++.h>
using namespace std;

// helper function - O(N)
long long totalTime(vector<int>& arr, int mid, int h){
    int n = arr.size();
    long long totalHrs = 0;
    
    for (int i = 0; i < n; i++)
    {
        // totalHrs += ceil(arr[i]/h);
        totalHrs += (arr[i] + mid - 1) / mid; 

        if(totalHrs > h) return totalHrs;  
    }
    return totalHrs;
}

// naive approach - O(maxVal)
// int minEatingSpeed(vector<int>& arr, double h){
//     int n = arr.size();
//     int maxVal = *max_element(arr.begin(), arr.end());

//     for (int i = 1; i <= maxVal; i++)
//     {
//         int reqTime = totalTime(arr, i, h);

//         if (reqTime <= h)
//         {
//             return i;
//         }
//     }
//     return -1; 
// }

// optimized approach Using Binary Search - O(log M)
int minEatingSpeed(vector<int>& arr, int h){
    int n = arr.size();
    int low = 1, high = *max_element(arr.begin(), arr.end());
    

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if(totalTime(arr, mid, h)<= h){
            high = mid - 1;
        }
        else{
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
    
    int h = 0;
    cin>>h;
    
    cout<<minEatingSpeed(arr, h);

    return 0;
}