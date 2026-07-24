/*
Given the root of a Binary Tree, find the length of the longest path consisting of connected nodes such that each next node has a value exactly 1 greater than its parent.

The path must move from parent to child only and follow increasing consecutive values.

If no such path exists, return -1.
*/
#include<iostream>
using namespace std;
// Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    void solve(Node* root, int cur, int& ma) {
        if(root->left) {
            if((root->data+1) == root->left->data) {
                ma = max(ma, cur+1);
                solve(root->left, cur+1, ma);
            }
            else
                solve(root->left, 1, ma);
        }
        
        if(root->right) {
            if ((root->data+1) == root->right->data) {
                ma = max(ma, cur+1);
                solve(root->right, cur+1, ma);
            }
            else
                solve(root->right, 1, ma);
        }
    }
    
    int longestConsecutive(Node* root) {
        int ma = 1;
        solve(root, 1, ma);
        if(ma == 1)
            return -1;
            
        return ma;
    }
};