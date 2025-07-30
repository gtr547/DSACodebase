// PS: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

// Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, 
// such that x squared is less than or equal to n (x*x <= n). 
// In other words, we need to determine the floor value of the square root of n.

#include <bits/stdc++.h>
using namespace std;


// naive approach - O(N)
// int squareRoot(int n){

//     int ans = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         if (i * i <= n)
//         {
//             ans = i;
//         }
//         else
//         {
//             break;
//         }
    
//     }
//     return ans;

// }

// optimal approach using binary search
int squareRoot(int n){
    int ans = 1;

    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
         
    }
    
    return ans;
}

int main() {
    // Write your code here
    int n;
    cin>>n;

    cout<<squareRoot(n);

    return 0;
}