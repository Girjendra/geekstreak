/*
Given root of a Binary Search Tree (BST) and an integer k, find the minimum absolute difference between k and the
value of any node in the BST.

Examples:
Input: root = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4], k = 13
Output: 2
Explanation: The node with value 11 is closest to k = 13. So, the minimum absolute difference is |11 - 13| = 2.

Input: root = [8, 1, 9, N, 4, N, 10, 3], k = 9
Output: 0
Explanation: The node with value 9 is closest to k = 9. So, the minimum absolute difference is |9 - 9| = 0.

Constraints:
1 ≤ size of binary tree, k ≤ 10^5
0 ≤ Node.data ≤ 10^5
*/
#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;









// Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// TC : O(n) + O(logn) + O(logn) ~ O(n) SC : O(n)
class Solution {
public:
    void solve(Node* root, vector<int>& ans) {
        if(!root)
            return ;

        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }
    
    int minDiff(Node *root, int k) {
        vector<int> ans;
        solve(root, ans);
        
        auto it = upper_bound(ans.begin(), ans.end(), k);
        int ans2 = INT_MAX;
        if(it != ans.end())
            ans2 = min(ans2, abs(*it - k));
        
        if(it != ans.begin())
            ans2 = min(ans2, abs(*prev(it) - k));
            
        return ans2;
    }
};






// TC : O(logn) SC : O(1)
class Solution {
public:
    void solve(Node* root, int k, int& ans) {
        if(!root)
            return ;
        
        ans = min(ans, abs(root->data - k));
        if(k > root->data)
            solve(root->right, k, ans);
        else
            solve(root->left, k, ans);
    }
    
    int minDiff(Node *root, int k) {
        int ans = INT_MAX;
        solve(root, k, ans);
        
        return ans;
    }
};