#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t){
    if (s.length() != t.length())
    {
        return false;
    }

    map<char, char> mpp;

    for(int i = 0;  i < s.length(); i++){
        if(mpp.find(s[i]) != mpp.end()){
            // s[i] exist as the key in the map
            if (mpp[s[i]] != t[i])
            {
                // inconsistenat mapping
                return false;
            }
            
        }
        else
        {
            // s[i] is not a key yet
            bool valueExist = false;

            for(auto it : mpp){
                if (it.second == t[i])
                {
                    // t[i] already exist as a value in map
                    valueExist = true;
                    break;
                }
            }
            if(valueExist){
                // t[i] is already mapped to another key
                return false;
            }

            mpp.insert(make_pair(s[i], t[i]));
        }
        
    }
    return true;
    
}

int main() {
    // Write your code here
    string s;
    string t;

    getline(cin, s);
    getline(cin, t);

    isIsomorphic(s, t)? cout<<"True" : cout<<"False" ;
    return 0;
}