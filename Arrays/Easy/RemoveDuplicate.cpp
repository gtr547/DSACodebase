// Given an sorted array, return the number of unique elements present in that array

#include <bits/stdc++.h>
using namespace std;


// brute force solution using hashset 
int findUnique(vector<int> arr){
    set<int> hst;
    for (int i = 0; i < arr.size(); i++)
    {
        hst.insert(arr[i]);
    }

    int i = 0;

    for(auto it: hst){
        arr[i] = it;
        i++;
    }

    return i;
    
}

// optimal solution using two pointer approach
int findUnique(vector<int> arr){
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j]!=arr[i])
        {
            arr[i+1] = arr[j];
            i++;
        }
        
    }
    return i+1;
    
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

    cout<<" "<<findUnique(arr);
    

    return 0;
}
