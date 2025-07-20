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
// int majElem(vector<int> &arr){
//     int n =  arr.size();

//     map<int, int> mpp;

//     for (int i = 0; i < n; i++)
//     {
//         mpp[arr[i]]++;
//     }

//     for (auto it :mpp)
//     {
//         if(it.second > n / 2){
//             return it.first;
//         }
//     }
    
//     return -1;

// }


// optimal approach (using Moore's voting algorithm)
int majElem(vector<int> &arr){
    int n =  arr.size();
    
    int cnt = 0;
    int elem;

    // finding the majority elem if it exist
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            elem = arr[i];
        }
        else if (arr[i] == elem)
        {
            cnt ++;
        }
        else
        {
            cnt --;
        }
        
    }

    // checking if a majority elem exist in the array
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elem)
        {
            cnt2 ++;
        }
        
    }

    if (cnt2 > (n/2))
    {
        return elem;
    }
    else
    {
        return -1;
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

    cout<<majElem(arr)<<endl;
   
        

    return 0;
}