// You are given an array of prices where prices[i] is the price of a given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. 
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <bits/stdc++.h>
using namespace std;

int stockBuyNSell(vector<int>& arr){
    int n = arr.size();
    int minPrice = arr[0], profit = 0;

    for (int i = 1; i < n; i++)
    {
        int currProfit = arr[i] -minPrice;
        
        profit = max(profit, currProfit);

        minPrice = min(minPrice, arr[i]);
    }
    
    return profit;
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

    cout<<stockBuyNSell(arr)<<endl;
        

    return 0;
}