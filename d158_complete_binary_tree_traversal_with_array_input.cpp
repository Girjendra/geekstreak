/*
Given an integer array arr[] representing the nodes of a Complete Binary Tree in level order traversal, return the nodes at each level in sorted ascending order.

For every level of the binary tree, sort the values present at that level independently and return the resulting levels as a 2D array, where the i-th row contains the sorted values of the i-th level.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        int le = 0;
        vector<vector<int>> ans;
        int i = 0, n = arr.size();
        
        while((n - i) >= (1 << le)) {
            int need = (1 << le);
            vector<int> temp;
            
            int end = i + need;
            while(i < end) {
                temp.push_back(arr[i]);
                i++;
            }
            
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            le++;
        }
        
        if(i != n) {
            vector<int> temp;
            
            while(i < n) {
                temp.push_back(arr[i]);
                i++;
            }
            
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        
        return ans;
    }
};
