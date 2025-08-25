// Given an array, implement merge sort to sort it.

#include <bits/stdc++.h>
using namespace std;

// merge function
void merge(vector<int>& arr, int low, int high, int mid){
    vector<int> temp;
    int left = low, right = mid + 1;

    // merge the two halves
    while(left <= mid && right <= high){
        if(arr[left]<= arr[right]){
            temp.push_back(arr[left]);
            left ++;
        }
        else
        {
            temp.push_back(arr[right]);
            right ++;
        }
    }

    // copy the remaining elements from the left half
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy the remaining element from the right half
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // copy the sorted temporary array back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
}

// merge sort
void mergeSort(vector<int>& arr, int low, int high){
    if(low>=high) return;
    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, high, mid);
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

    mergeSort(arr, 0, arr.size()-1);

    for( int i : arr){
        cout<<i<<" ";
    }

    return 0;
}