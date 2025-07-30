// Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. 
// If the 'nth root is not an integer, return -1.

#include <bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m){
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low +(high - low) / 2;

        if (pow(mid,n) == m)
        {
            return mid;
        }
        else if (pow(mid,n) > m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    
    }
    return -1;
    
}

int main() {
    // Write your code here
    int n, m;

    cin>>n;
    cin>>m;

    cout<<nthRoot(n, m);

    return 0;
}