// Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

#include <bits/stdc++.h>
using namespace std;

int appearOnce(vector<int> arr){
    int xorr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xorr ^= arr[i];
    }

    return xorr;

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


    cout<<appearOnce(arr);    

    return 0;
}