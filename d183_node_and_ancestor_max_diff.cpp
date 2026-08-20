/*
Given the root of a binary tree, find the maximum difference between an ancestor node A and its descendant node B, i.e., maximize A - B.
*/
#include<iostream>
#include <climits>
using namespace std;

//  Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// TC : O(N), SC: O(H) where H is the height of the tree
class Solution {
  public:
    int solve(Node* root, int& ans) {
        if(!root)
            return INT_MAX;
        
        int lm = solve(root->left, ans);
        int rm = solve(root->right, ans);
        
        ans = max(ans, root->data - lm);
        ans = max(ans, root->data - rm);
        
        return min(lm, min(rm, root->data));
    }
    
    int maxDiff(Node* root) {
        int ans = INT_MIN;
        solve(root, ans);    
        return ans;
    }
};