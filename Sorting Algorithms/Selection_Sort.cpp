#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr){
    for (int i = 0; i <= arr.size()-2; i++)
    {
        int min = i;
        //finding the minimum element
        for (int j = i; j <= arr.size()-1; j++)
        {
            if(arr[j]<arr[min]) min = j;
        }
        //swapping minimum element with the current element
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;        
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


    selectionSort(arr);
    
    for (int i = 0; i <= arr.size()-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}