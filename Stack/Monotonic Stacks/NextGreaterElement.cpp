/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
T.C - O(2N)
*/



#include <bits/stdc++.h>
using namespace std;



vector <int> findNGE(vector <int>& nums1, vector <int>& nums2){
    stack <int> st;
    map <int, int> mpp;
    vector <int> res;

    for(int i = nums2.size()-1; i>=0; i--){
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }

        if (st.empty()) mpp[nums2[i]] = -1;
        else mpp[nums2[i]] = st.top();
        st.push(nums2[i]); 
    }

    for(int i = 0; i < nums1.size(); i++){
        res.push_back(mpp[nums1[i]]);
    }

    return res;
}

int main() {
    // Write your code here
    vector <int> nums2 = {1,2,3,4};
    vector <int> nums1 = {2,4};

    vector<int> nge = findNGE(nums1, nums2);

    for(const auto& val: nge){
        cout << val << " ";
    }

    return 0;
}