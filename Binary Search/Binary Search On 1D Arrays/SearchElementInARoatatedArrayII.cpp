// Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k.
// Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& arr, int k ){
    int n = arr.size();
    int low = 0 , high = n-1;
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            return true;
        }
        
        //Shrinking down the search space to handle duplicates
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low ++;
            high --;
            continue;
        }


        // left is sorted
        if (arr[low] <= arr[mid])
        {
            // check if elem lies in the sorted half
            
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
               
        }
        // right is sorted 
        else
        {
            if (arr[mid] <= k && k <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            
        }
          
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
    
    int k = 0;
    cin>>k;
    
    search(arr, k) ? cout<<"true" : cout<<"false" ;
    
    return 0;
}
