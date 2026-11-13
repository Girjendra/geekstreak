/*
Given the roots r1 and r2 of two Binary Search Trees (BST), find all nodes that are present in both
trees i.e. the intersection nodes of the two BSTs.
Return the common node values in sorted order.

Examples:
Input: r1 = [5, 1, 10, 0, 4, 7, N, N, N, N, N, N, 9], r2 = [10, 7, 20, 4, 9, N, N]  
Output: [4, 7, 9, 10]
Explanation: The values present in both BSTs are 4, 7, 9, and 10. Hence, the answer is [4, 7, 9, 10].

Input: r1 = [10, 2, 11, 1, 3, N, N], r2 = [2, 1, 3]
Output: [1, 2, 3]
Explanation: The values 1, 2, and 3 are present in both BSTs. Hence, the answer is [1, 2, 3].

Constraints:
1 ≤ size of binary trees ≤ 10^5
0 ≤ Node.data ≤ 10^9
*/
#include<iostream>
#include <set>
#include <vector>
using namespace std;







// Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// TC = O(n1 + n2), SC = O(n1 + n2)
class Solution {
public:
    void findnodes(Node* root, set<int>& s) {
        if(!root)
            return ;
            
        findnodes(root->left, s);
        s.insert(root->data);
        findnodes(root->right, s);
    }
    
    vector<int> findCommon(Node* r1, Node* r2) {
        set<int> s1, s2;
        findnodes(r1, s1);
        findnodes(r2, s2);
        
        vector<int> ans;
        for(int it : s1)
            if(s2.find(it) != s2.end())
                ans.push_back(it);
                
        return ans;
    }
};