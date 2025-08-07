#include <bits/stdc++.h>
using namespace std;

// Naive approach T.C-O(N) S.C-O(N)
// string removeOuterParentheses(string s) {
//     int cnt = 0;
//     string ans = "";

//     for(int i = 0; i < s.length(); i++){
//         if(s[i] == '('){
//             if (cnt > 0)
//             {
//                 ans.push_back(s[i]);
//             }
//             cnt ++;
//         }
//         else if( s[i] == ')'){
//             cnt --;
//             if (cnt > 0)
//             {
//                 ans.push_back(s[i]);
//             }
//         }
//     }
//     return ans;
// }

// optimal approach T.C-O(N) S.C-O(1)
string removeOuterParentheses(string s) {
    int cnt = 0;
    int i = 0, j = 0;

    while (i < s.length()) {
        char c = s[i];

        if (c == '(') {
            if (cnt > 0) {
                s[j] = c;
                j++;
            } 
            cnt++;
        } else {
            cnt--;
            if (cnt > 0) {
                s[j] = c;
                j++;
            }
        }
        i++;
    }
    s.resize(j);
    return s;
}


int main() {
    string str;
    
    
    cin >> str;
    
    cout <<removeOuterParentheses(str)<< endl;
    
    return 0;
}