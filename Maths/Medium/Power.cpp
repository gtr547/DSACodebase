// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

#include <bits/stdc++.h>
using namespace std;

// optimal iterative approach -using binomial exponentiation        T.C - O(log n)      S.C - O(1)
double myPow(double x, int n){
    // hendling edgecases
    if(x == 1 || n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == -1 && n % 2 == 0) return 1.0;
    if(x == -1 && n % 2 != 0) return -1.0;

    long binary = n;

    // incase n is a -ve integer
    if(binary < 0){
        x = 1/x;
        binary = -binary;
    }

    double ans = 1;

    while (binary > 0 )
    {
        if(binary % 2 == 1){
            ans *= x;
        }
        x *= x;
        binary /= 2;
    }
    return ans;
}

int main() {
    // Write your code here
    double x;
    cin>>x;

    int n;
    cin>>n;


    cout<<myPow(x, n);

    return 0;
}