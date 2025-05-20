#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr){
    for (int i = arr.size() - 1; i > 0; i--)
    {
        // flag to check, if the array is already sorted or not 
        int didSwap = 0;
        for (int j = 0; j <= i-1; j++)
        {
            // check if the elem in the left > current elem
            if(arr[j]>arr[j+1]){
                //swap elems
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

                didSwap = 1;
            }
        }
        if(didSwap == 0){
            break;
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

        if(n != -1){
            arr.push_back(n);
        }
        else break;
    }


    bubbleSort(arr);
    
    for (int i = 0; i <= arr.size()-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}