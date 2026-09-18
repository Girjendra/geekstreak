/*
Given the root of a Binary Search Tree (BST) containing n (n > 1) nodes, find the minimum absolute difference between the values of any two different nodes in the tree.

Return the minimum absolute difference.

Constraints:
2 ≤ size of binary tree ≤ 105
0 ≤ node.data ≤ 106
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;





// Binary Tree Node Structure
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



// TC = O(n)  SC = O(n)
class Solution {
  public:
    void inorder(vector<int> &inord, Node *root) {
        if (!root)
            return;
    
        inorder(inord, root->left);
        inord.push_back(root->data);
        inorder(inord, root->right);
    }
    
    int absDiff(Node *root) {
        vector<int> inord;
        inorder(inord, root);

        int mini = INT_MAX;
        int n = inord.size();

        for (int i = 0; i < n - 1; i++)
            mini = min(mini, inord[i + 1] - inord[i]);

        return mini;  
    }
};



// TC = O(n)  SC = O(h)
class Solution {
  public:
    void inorder(Node *curr, Node*& prev, int &ans) {
        if (curr == nullptr)
            return;

        inorder(curr->left, prev, ans);

        if (prev != nullptr)
            ans = min(ans, curr->data - prev->data);

        prev = curr;
        
        inorder(curr->right, prev, ans);
    }
    
    int absDiff(Node *root) {
        Node *prev = nullptr;
        int ans = INT_MAX;

        inorder(root, prev, ans);

        return ans;
    }
};