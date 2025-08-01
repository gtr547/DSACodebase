// You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. 
// You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.

// Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int mid, int m, int k){
    int n = arr.size();
    int cnt = 0, bNo = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= mid)
        {
            // blooming is possible
            cnt ++;
        }
        else
        {
            bNo += (cnt/k);
            if (bNo >= m) return true;
            cnt = 0;
        }

    }
    bNo += (cnt/k);

    if(bNo >= m) return true;
    else return false;
}



int minDays(vector<int>& arr, int m, int k){
    int n = arr.size();
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    if (1LL * m * k > n)
    {
        return -1;
    }
    
    while (low <= high)
    {
        int mid = low +(high - low) / 2;

        if(isPossible(arr, mid, m, k) == 1){
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
    
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
    
    int m = 0, k = 0;
    cin>>m;
    cin>>k;


    cout<<minDays(arr, m , k);
    

    return 0;
}