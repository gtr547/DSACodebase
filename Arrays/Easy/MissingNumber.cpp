// Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// int missingNum(vector<int> arr, int a){
//     int n = arr.size();
    
//     for (int i = 1; i <= a ; i++)
//     {
//         int flag = 0;
//         for ( int j = 0; j <= n-1; j++)
//         {
//             if (arr[j] == i)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0)
//         {
//             return i;
//         }
        
//     }
    
// }

// Better Solution (using Hash)
// int missingNum(vector<int> arr, int a){
//     map<int,int> hash;

//     for (int i = 0; i <= arr.size()-1; i++)
//     {
//         hash[arr[i]] = 1;
//     }

//     for (int i = 1; i <= a; i++)
//     {
//         if (hash[i] != 1)
//         {
//             return i;
//         }
        
//     }

//     return -1;
    
// }

// Optimal Solution using summation
// int missingNum(vector<int> arr, int a){

//     int expSum = (a*(a+1))/2;
//     int sum = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         sum += arr[i];
//     }

//     return (expSum - sum);    

// }

// optimal Solution using XOR
int missingNum(vector<int> arr, int a){

    int xor1 = 0, xor2 = 0;

    // for (int i = 0; i <= a; i++)
    // {
    //     xor1 ^= i;
    // }

    for (int i = 0; i < arr.size(); i++)
    {
        xor2 ^= arr[i];
        xor1 ^= (i+1);
        xor1 ^= a;
    }

    return xor1 ^ xor2;  

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
    
    int a;
    cin>>a;

    cout<<missingNum(arr, a);

    return 0;
}