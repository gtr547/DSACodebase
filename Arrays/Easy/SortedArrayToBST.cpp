// Given an integer array nums where the elements are sorted in ascending order, convert it to a binary search tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


TreeNode* sortedArrayToBST(vector<int>& arr, int low, int high){
    if (low > high) return nullptr;

    int mid = low + (high - low) / 2;
    TreeNode* node = new TreeNode(arr[mid]);

    node->left = sortedArrayToBST(arr, low, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, high);

    return node;
}


void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    vector<string> result;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }

    // Trim trailing "null"s for cleaner output
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    // Output the result
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
}

int main() {
    string line;
    getline(cin, line);

    vector<int> arr;
    stringstream ss(line);
    int n;
    while (ss >> n) arr.push_back(n);

    TreeNode* root = sortedArrayToBST(arr, 0, arr.size() - 1);
    printLevelOrder(root);

    return 0;
}
