/*
Given the roots of two binary trees root1 and root2, check whether the nodes at every corresponding level of the two trees are anagrams of each other.

Two levels are considered anagrams if they contain the same node values with the same frequencies, regardless of their order.

Constraints:
1 ≤ size of binary tree ≤ 105
1 ≤ node.data ≤ 106
The character N represents a null child.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;





// Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};




// TC : O(nlogn) SC : O(n)
class Solution {
public:
    void solve(Node* root, int lev, vector<vector<int>>& m) {
        if(!root)
            return;

        if(lev == m.size())
            m.push_back({});

        m[lev].push_back(root->data);

        solve(root->left, lev + 1, m);
        solve(root->right, lev + 1, m);
    }

    bool areAnagrams(Node* root1, Node* root2) {
        if(!root1 || !root2)
            return root1 == root2;

        if(root1->data != root2->data)
            return false;

        vector<vector<int>> m1, m2;

        solve(root1, 0, m1);
        solve(root2, 0, m2);

        if(m1.size() != m2.size())
            return false;

        for(int i = 0; i < m1.size(); i++) {
            sort(m1[i].begin(), m1[i].end());
            sort(m2[i].begin(), m2[i].end());

            if(m1[i] != m2[i])
                return false;
        }

        return true;
    }
};