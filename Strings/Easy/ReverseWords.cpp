// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. 
// The returned string should only have a single space separating the words. Do not include any extra spaces.


#include <bits/stdc++.h>
using namespace std;

// better approach - T.C : O(N), S.C : O(N)
string reverseWord(string s){
    int n = s.length();

    reverse(s.begin(), s.end());

    string ans = "";

    for(int i=0; i<n; i++){

        string word = "";

        while(i<n && s[i]!=' '){
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word.length() > 0)
        {
            ans += " " + word;
        }
        
    }

    return ans.substr(1);
    
}

int main() {
    string str; 

    getline(cin, str);
    
    cout<<reverseWord(str);
    
    return 0;
}