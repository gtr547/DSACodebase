/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. 

If it doesn't exist, return -1 for this number.
*/


#include <bits/stdc++.h>
using namespace std;



vector <int> findNGE(vector <int>& nums){
    int n = nums.size();
    stack <int> st;
    vector <int> nge(n);

    for(int i = 2*n-1; i >= 0; i--){
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if(i < n){
            nge[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[i % n]);
    }
    return nge;
}

int main() {
    // Write your code here
    vector <int> nums = {1,2,3,4,3};

    vector<int> nge = findNGE(nums);

    for(const auto& val: nge){
        cout << val << " ";
    }

    return 0;
}