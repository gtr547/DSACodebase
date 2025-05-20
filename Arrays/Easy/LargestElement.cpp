// Given an array find the largest element in that array


#include <bits/stdc++.h>
using namespace std;

int max(vector<int> arr){
    int max = arr[0];
    for (int i = 1; i < arr.size() ; i++)
    {
        if(arr[i]>max){
            max = arr[i];
        }
    }

    return max;
    
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

    cout<<" "<<max(arr);
    

    return 0;
}