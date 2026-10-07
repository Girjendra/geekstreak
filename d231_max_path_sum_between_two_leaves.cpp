/*
Given the root of a binary tree, where each node contains an integer value, find the maximum possible path sum
between any two leaf nodes. If the tree has fewer than two leaf nodes, return -1.

Examples:
Input: root = [3, 4, 5, -10, 4, N, N]
Output: 16
Explanation: 
The leaf nodes are -10, 4 (right child of 4), and 5.
Possible paths between leaf nodes are:
-10 -> 4 -> 3 -> 5 = -10 + 4 + 3 + 5 = 2
-10 -> 4 -> 4 = -10 + 4 + 4 = -2
4 -> 4 -> 3 -> 5 = 4 + 4 + 3 + 5 = 16
Hence, the maximum path sum is obtained from the path 4 -> 4 -> 3 -> 5, giving 16.

Input: root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, N, N, N, N, N, 0, N, N, N, N, 4, -1, N, N, 10]
Output: 27
Explanation: 
The leaf nodes are 2, -3, 1, 4, and 10.
Some possible paths between leaves are:
2 -> -8 -> 5 -> 1 = 2 + (-8) + 5 + 1 = 0
-3 -> -8 -> 5 -> 1 = -3 + (-8) + 5 + 1 = -5
2 -> -8 -> 5 -> -15 -> 6 -> 3 = 2 + (-8) + 5 + (-15) + 6 + 3 = -7
1 -> 5 -> -15 -> 6 -> 9 -> 0 -> 4 = 1 + 5 + (-15) + 6 + 9 + 0 + 4 = 10
3 -> 6 -> 9 -> 0 -> -1 -> 10 = 3 + 6 + 9 + 0 + (-1) + 10 = 27
Hence, the maximum path sum is obtained from the path 3 -> 6 -> 9 -> 0 -> -1 -> 10, giving 27.

Input: root = [3, 4, 1, -10, 4, N, N] 
Output: 12
Explanation:
The leaf nodes are -10, 4 (right child of 4), and 1.
Possible paths between leaf nodes are:
-10 -> 4 -> 4 = -10 + 4 + 4 = -2
-10 -> 4 -> 3 -> 1 = -10 + 4 + 3 + 1 = -2
4 -> 4 -> 3 -> 1 = 4 + 4 + 3 + 1 = 12
Hence, the maximum path sum is obtained from the path 4 -> 4 -> 3 -> 1, giving 12.

Constraints:
0 ≤ size of binary tree ≤ 10^4
-10^3 ≤ node.data ≤ 10^3
*/
#include<iostream>
#include <climits>
using namespace std;




// TC : O(n) SC : O(h)
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class Solution {
public:
    int solve(Node* root, int& ans, int& count) {

        // Leaf node
        if(!root->left && !root->right) {
            count++;
            return root->data;
        }

        int left = INT_MIN;
        int right = INT_MIN;

        // Left subtree
        if(root->left) {
            left = root->data + solve(root->left, ans, count);
        }

        // Right subtree
        if(root->right) {
            right = root->data + solve(root->right, ans, count);
        }

        // Path between two leaves can be formed
        // only when both children exist
        if(root->left && root->right) {
            ans = max(ans, left + right - root->data);
        }

        // Return maximum path sum from this node
        // to any leaf below it
        return max(left, right);
    }

    int maxPathSum(Node* root) {

        if(!root)
            return -1;

        int ans = INT_MIN;
        int count = 0;

        solve(root, ans, count);

        // Fewer than two leaves
        if(count < 2)
            return -1;

        return ans;
    }
};