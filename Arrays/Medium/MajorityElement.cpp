// Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. 
// You may consider that such an element always exists in the array.

#include <bits/stdc++.h>
using namespace std;

// brute approach
// int majElem(vector<int> &arr){
//     int n =  arr.size();
    
//     for (int i=0; i < n; i++)
//     {
//         int cnt = 0;
        
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 cnt++;
//             }
            
//         }
        
//         if (cnt > (n/2))
//         {
//             return arr[i];
//         }
        
        
//     }
   
//     return -1;

// }


// better approach (hashing)
int majElem(vector<int> &arr){
    int n =  arr.size();

    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it :mpp)
    {
        if(it.second > n / 2){
            return it.first;
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

    cout<<majElem(arr)<<endl;
   
        

    return 0;
}