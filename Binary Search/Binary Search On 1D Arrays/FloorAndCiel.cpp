// You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        
    }
    return ans;
    
}

int findCiel(vector<int>& arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] >= x){
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        
    }
    return ans;
    
    
}

pair <int, int> getFloorAndCiel(vector<int>& arr, int x){
    int f = findFloor(arr, x);
    int c = findCiel(arr, x);

    return make_pair(f, c);
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

    pair<int, int> ans = getFloorAndCiel(arr, x);

    cout<<" "<<ans.first<<" "<<ans.second;
   
    return 0;
}