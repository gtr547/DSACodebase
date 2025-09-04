// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

//     Whitespace: Ignore any leading whitespace (" ").
//     Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
//     Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. 
//     If no digits were read, then the result is 0.
//     Rounding: If the integer is out of the 32-bit signed integer range [-23^1, 2^31 - 1], then round the integer to remain in the range. 
//     Specifically, integers less than -231 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.

// Return the integer as the final result.

#include <bits/stdc++.h>
using namespace std;

// iterative approach       T.C - O(N)          S.C - O(1)
int myAtoi(string s){
    int ans = 0;

    // counting the leading whiteSpaces 
    int whiteSpaceCount = 0;
    for(int i = 0; i < s.length() && s[i] == ' '; i++){
        whiteSpaceCount++;
    }

    // string slicing - removing leading whitespaces
    string str = s.substr(whiteSpaceCount);

    // flaging the sign
    int sign = 1;
    if(str[0] == '-' || str[0] == '+'){
        sign = (str[0] == '-')? -1: 1;
        str = str.substr(1);
    }

    // counting the leading zeroes
    int leadingZeroesCount = 0;
    for(int i = 0; i<str.length() && str[i] == '0'; i++){
        leadingZeroesCount++;
    }

    // parsing from string to int
    for(int i = leadingZeroesCount; i<str.length() && isdigit(str[i]); i++){
        // converting character to integer
        int digit = str[i] - '0'; 

        // rounding in case of integer overflow
        if(ans > (INT_MAX -digit) / 10){
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        // parsing
        ans = ans * 10 + digit;  
    }
    return (ans * sign);
}


int main() {
    string str; 

    getline(cin, str);
    
    cout<<myAtoi(str);
    
    return 0;
}