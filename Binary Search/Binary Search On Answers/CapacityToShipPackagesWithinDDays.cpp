// You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
// The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every daysCnt in the same order as they appear in the array. 
// The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

#include <bits/stdc++.h>
using namespace std;


int daysReq(vector<int>& arr, int mid){
    int n = arr.size();

    int daysCnt = 1, load = 0;

    for (int i = 0; i < n; i++)
    {
        if (load + arr[i] > mid)
        {
            daysCnt++;
            load = arr[i];
        }
        else{
            load += arr[i];
        }
    }
    return daysCnt;  
}


int minCapacity(vector<int>& arr, int k){
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (daysReq(arr,mid) <= k)
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
    
    int d = 0;
    cin>>d;
    
    cout<<minCapacity(arr, d);
    

    return 0;
}