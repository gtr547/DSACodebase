// You are given a string num, representing a large integer. 
// Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.


#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(2N) Space Complexity - O(1)
string largestOddNumber(string s) {
    int n = s.length();

    int ind = -1;

    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2 == 1) {
            ind = i;
            break;
        }
    }
    if (ind == -1)
        return "";

    int i = 0;

    while (i <= ind && (s[i] == '0')) {
        i++;
    }

    return s.substr(i, ind + 1);
}


int main() {
    string str; 

    getline(cin, str);
    
    cout<<largestOddNumber(str);
    
    return 0;
}