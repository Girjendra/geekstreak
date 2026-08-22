/*
Given root of a binary tree and the values of its two nodes p and q, count turns required to travel from node p to q.

A turn occurs whenever the direction of movement changes from left to right or right to left while traversing the tree.
If the path between the two nodes does not involve any turns (i.e., the nodes lie on the same straight path), return -1.
Note: All node values are distinct.
*/
#include<iostream>
using namespace std;


// Structure of Binary Tree Node
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

// TC : O(N), SC: O(H)
class Solution {
  public:
    int findTurns(Node* root, int target, char prev) {
        if(!root)
            return -1;
    
        if(root->data == target)
            return 0;
    
        int left = findTurns(root->left, target, 'L');
    
        if(left != -1) {
            if(prev == 'R')
                return left + 1;
            return left;
        }
    
        int right = findTurns(root->right, target, 'R');
    
        if(right != -1) {
            if(prev == 'L')
                return right + 1;
            return right;
        }
    
        return -1;
    }
    
    Node* LCA(Node* root, int p, int q) {
        if(!root)
            return nullptr;
    
        if(root->data == p || root->data == q)
            return root;
    
        Node* left = LCA(root->left, p, q);
        Node* right = LCA(root->right, p, q);
    
        if(left && right)
            return root;
    
        if(left)
            return left;
    
        return right;
    }
    
    char getDirection(Node* root, int target) {
        if(root->left && findTurns(root->left, target, ' ') != -1)
            return 'L';

        return 'R';
    }
    
    int numberOfTurns(Node* root, int p, int q) {
        Node* common = LCA(root, p, q);

        int pt = findTurns(common, p, ' ');
        int qt = findTurns(common, q, ' ');

        if(pt == -1 || qt == -1)
            return -1;

        int ans = pt + qt;

        if(p != common->data && q != common->data) {
            char dp = getDirection(common, p);
            char dq = getDirection(common, q);

            if(dp != dq)
                ans++;
        }

        return ans == 0 ? -1 : ans;
    }
};