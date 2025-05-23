//  Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr, int k){
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i]==k)
        {
            return i;
        }
        
    }

    return -1;
    
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


    cout<<linearSearch(arr, k)<<" ";
    

    return 0;
}