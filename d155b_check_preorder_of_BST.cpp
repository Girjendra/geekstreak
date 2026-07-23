/*
Given an array arr[ ] consisting of distinct integers, check if the given array can represent preorder traversal of a BST.
*/
#include<iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;


class Solution {
  public:
    bool solve(vector<int> &arr, int l, int r) {
        if(l >= r)
            return true;
            
        int st = l + 1;
        
        while(st <= r && arr[st] < arr[l])
            st++;
            
        for (int k = st; k <= r; k++)
            if (arr[k] < arr[l])
                return false;
    
        bool lb = solve(arr, l+1, st-1);
        bool rb = solve(arr, st, r);
        
        return (lb && rb);
    }
    
    bool canRepresentBST(vector<int> &arr) {
        return solve(arr, 0, arr.size()-1);
    }
};


class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> s;

        int root = INT_MIN;
    
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < root)
                return false;
                
            while (!s.empty() && s.top() < arr[i]) {
                root = s.top();
                s.pop();
            }
    
            s.push(arr[i]);
        }
        
        return true;
    }
};