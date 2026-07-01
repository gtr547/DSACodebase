#include <bits/stdc++.h>
using namespace std;

vector<int> findPSE(vector<int> num){
    int n = num.size();
    stack<int> st;
    vector<int> pse(n);
    
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top()>=num[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(num[i]);
    }
    return pse;
    
}

int main() {
    // Write your code here
    vector <int> nums = {1,2,3,4};
    

    vector<int> pse = findPSE(nums);

    for(const auto& val: pse){
        cout << val << " ";
    }

    return 0;
}