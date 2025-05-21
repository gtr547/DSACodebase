// Given an array with length N, rotate the array right by k places

#include <bits/stdc++.h>
using namespace std;

// Brute Force approach
// void rotateRightByK(vector<int>& arr, int k){
//     int n = arr.size();

//     // multiples of k will result in the same array
//     k = k%n;

//     vector<int> temp;
//     // Store the last k elements in temp
//     for (int i = n-k; i <= n-1; i++)
//     {
//         temp.push_back(arr[i]);
//     }

//     // shift element from index n - k - 1 to 0 to the right
//     for (int i = n-k-1; i <= 0; i--)
//     {
//         arr[i+k] = arr[i];
//     }

//     // copy elements from back from the temp to the front
//     for (int i = 0; i <= k-1; i++)
//     {
//         arr[i] = temp[i];
//     }
    
// }

// Optimal Approach
void rotateRightByK(vector<int>& arr, int k){
    int n = arr.size();
    reverse(arr.end()-k, arr.end());
    reverse(arr.begin(), arr.end()-k);
    reverse(arr.begin(), arr.end());

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


    rotateRightByK(arr,k);

    for (int i = 0; i <= arr.size()-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}