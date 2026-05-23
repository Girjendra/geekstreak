/*
Given a root of a binary tree with n nodes, where each node may contain positive or negative values,
convert it into a tree such that each node’s new value is equal to the sum of all values in its left
and right subtrees (based on the original tree). For leaf nodes, update their values to 0.
*/
#include<iostream>
using namespace std;
/* Structure for Tree Node
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
*/
class Solution {
  public:
    int solve(Node* root) {
        if(!root)
            return 0;
            
        if(!root->left && !root->right){
            int temp = root->data;
            root->data = 0;
            return temp;
        }
    
        int left = solve(root->left);
        int right = solve(root->right);
        
        int tmep = root->data;
        root->data = left+right;
        
        return root->data + tmep;
    }
    
    void toSumTree(Node *root) {
        solve(root);
    }
};