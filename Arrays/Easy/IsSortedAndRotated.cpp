//Given an array check if an array is a rotation of a non decreasing sorted array(duplicates allowed)

#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr){
    int drop = 0;
    int n = arr.size();
    for (int i = 1; i <= n-1; i++)
    {
        if(arr[i]<arr[i-1]){
            drop++;
        }
    }
    if(arr[0]<arr[n-1]){
        drop++;
    }

    if(drop<=1){
        return true;
    }
    else
    {
        return false;
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

    isSorted(arr)? cout<<"True" : cout<<"False" ;
    

    return 0;
}