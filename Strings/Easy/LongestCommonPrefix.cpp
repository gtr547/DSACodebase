// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

#include <bits/stdc++.h>
using namespace std;

// naive approach T.C - O(N * L), S.C - O(L), where 'L' is the length of the first string.
string longestCommonPrefix(vector<string>& arr) {
    int n = arr.size();

    string ans = "";

    for (int i = 0; i < arr[0].length(); i++) {
        char ch = arr[0][i];

        bool match = true;

        for (int j = 1; j < n; j++) {
            if (arr[j].size() <= i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }

        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

int main() {
    // Write your code here
    vector<string> arr;
    string line;
    
    
    getline(cin, line);
    
    // Parse the line into individual words
    stringstream ss(line);
    string word;
    while (ss >> word) {
        arr.push_back(word);
    }
   
    cout << longestCommonPrefix(arr);
    return 0;
}