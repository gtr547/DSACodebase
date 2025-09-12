// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.
//     Every close bracket has a corresponding open bracket of the same type.

#include <bits/stdc++.h>
using namespace std;

bool isValid(string str){
    stack <char> st;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            st.push(str[i]);
        }
        else{
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();

            if(str[i] == ')' && ch != '(' || str[i] == ']' && ch != '[' || str[i] == '}' && ch != '{'){
                return false;
            }
        }
    }
    return st.empty();
}



int main() {
    // Write your code here
    string s;

    getline(cin, s);

    isValid(s) ? cout<<"True" : cout<<"False";

    return 0;
}