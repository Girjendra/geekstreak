/*
Given two arrays pre[] and preMirror[] of size n containing unique elements, where pre[] represents the preorder traversal of a full binary tree and preMirror[] represents the preorder traversal of its mirror tree, construct the original full binary tree using these traversals.

Note: A general binary tree cannot be uniquely constructed using these two traversals. However, a full binary tree can be constructed uniquely from the given traversals without any ambiguity.
*/
// Structure of Binary Tree Node
#include<iostream>
#include <vector>
using namespace std;
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

class Solution {
  public:
    Node* solve(int poi, int poj, int pomi, int pomj, vector<int> &pre,
                vector<int> &prem) {

        if(poi > poj)
            return NULL;

        Node* root = new Node(pre[poi]);

        if(poi == poj)
            return root;

        int leftRoot = pre[poi + 1];
        int x = pomi + 1;

        while(x <= pomj) {
            if(prem[x] == leftRoot)
                break;
            x++;
        }

        int leftSize = pomj - x + 1;
        root->left = solve(poi + 1, poi + leftSize, x, pomj, pre, prem);
        root->right = solve(poi + leftSize + 1, poj, pomi + 1, x - 1, pre, prem);

        return root;
    }

    Node* constructBinaryTree(vector<int> &pre, vector<int> &prem) {
        int n = pre.size();
        return solve(0, n - 1, 0, n - 1, pre, prem);
    }
};