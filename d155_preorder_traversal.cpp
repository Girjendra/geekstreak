/*
Given the root of a binary tree, your task is to return its Preorder traversal.

Note: A preorder traversal first visits the node, then visits the left child (including its entire subtree), and finally visits the right child (including its entire subtree).
*/
#include<iostream>
#include <vector>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x){
            data = x;
            left = right = NULL;
        }
};


class Solution {
  public:
    void preorder(Node* root, vector<int>& pre) {
        if(!root)
            return ;
        
        pre.push_back(root->data);
        
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    
    vector<int> preOrder(Node* root) {
        vector<int> pre;
        
        preorder(root, pre);
        
        return pre;
    }
};