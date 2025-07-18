// Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions.


#include <bits/stdc++.h>
using namespace std;

// for brute approach use any in-place sorting algorithm available out there, like merge sort

// better - Counting sort approach
// void sort(vector<int> &arr){
//     int n = arr.size();
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0) cnt0++;

//         else if (arr[i] == 1) cnt1++;
        
//         else cnt2++;
//     }

//     for (int i = 0; i < cnt0; i++) arr[i] = 0;
       
//     for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1;
        
//     for (int i = cnt0 + cnt1; i < n; i++)  arr[i] = 2;
    
// }


// Optimal approach using the Dutch National flag algorithm
void sort(vector<int> &arr){
    int n = arr.size();
    int low = 0; int mid = 0; int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;

            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;

            high--;
        }
    }
    
}

int main() {
    // Write your code here
    vector<int> arr;
    
    int n = 0;

    while (true)
    {
        cin>>n;

        if(n == 0 || n == 1 || n == 2 ){
            arr.push_back(n);
        }
        else if (n == -1)
        {
            break;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
        
    }

    sort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}