/*
Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line.
Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.
*/
#include<iostream>
#include <map>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    void solve(Node *node, int hd, map<int, int> &mp) {
 
        if (node == NULL) return;
    
        solve(node->left, hd-1, mp);
    
        mp[hd] += node->data;

        solve(node->right, hd+1, mp);
    }

    vector<int> verticalSum(Node* root) {
         map <int, int> mp;
    
        solve(root, 0, mp);
    	
      	vector<int> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
          	ans.push_back(it->second);
        
      	return ans;  
    }
};