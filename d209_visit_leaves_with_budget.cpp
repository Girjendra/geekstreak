/*
Given a binary tree and an integer k, where you start from the root at level 1. The cost of visiting a leaf node is equal to the level of that leaf node. You can visit any number of leaf nodes, but the total cost of visiting them must not exceed k.

Return the maximum number of leaf nodes that can be visited within the given budget.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Binary Tree Node Structure
class Node {
  public:
  
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};



// TC : O(nlogn) 
class Solution {
  public:
    void solve(Node* root, vector<int>& costs, int c) {
        if(!root->left && ! root->right) {
            costs.push_back(c);
            return ;
        }
        
        if(root->left)
            solve(root->left, costs, c+1);
            
        if(root->right)
            solve(root->right, costs, c+1);
    }
    
    int getCount(Node *root, int k) {
        vector<int> costs;
        
        solve(root, costs, 1);
        
        sort(costs.begin(), costs.end());
        
        int ans = 0;
        int temp = 0;
        
        for(int it : costs) {
            if(temp + it > k)
                break;
                
            ans++;
            temp += it;
        }
        
        return ans;
    }
};