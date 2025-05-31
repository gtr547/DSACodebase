//  Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

#include <bits/stdc++.h>
using namespace std;

int maxOnes(vector<int> arr){

    int maxi = 0;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            cnt ++;
            maxi = max(maxi, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    return maxi;
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


    cout<<maxOnes(arr)<<" ";
    

    return 0;
}