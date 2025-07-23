#include <bits/stdc++.h>
using namespace std;

int binarySearch (vector<int>& arr, int k, int low, int high){
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low)/2;

    if (arr[mid] == k)
    {
        return mid;
    }
    else if (k > arr[mid])
    {
        return binarySearch(arr, k, mid + 1, high);
    }
    else
    {
        return binarySearch(arr, k, low, mid - 1);
    }

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
    
    cout<<"Item found at index "<<binarySearch(arr, k, 0, arr.size());

    return 0;
}