// Given an array with length N, rotate the array left by k places

#include <bits/stdc++.h>
using namespace std;

// Brute Force approach
void rotateLeftByK(vector<int>& arr, int k){
    int n = arr.size();

    // multiples of k will result in the same array
    k = k%n;

    vector<int> temp;

    // putting the first k elements int the temp array
    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }

    // shifting the places of the rest of the elements
    for (int i = k; i < n; i++)
    {
        arr[i-k] = arr[i];
    }

    // appending the elements of the temp in the original array
    for (int i = n-k; i < n; i++)
    {
        arr[i] = temp[i-(n-k)];
    }
    
}

// Optimal Approach
void rotateLeftByK(vector<int>& arr, int k){
    int n = arr.size();
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.begin() + n);
    reverse(arr.begin(), arr.begin() + n);

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


    rotateLeftByK(arr,k);

    for (int i = 0; i <= arr.size()-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}