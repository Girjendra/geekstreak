/*
Given a sorted array arr[]. For each i(0 ≤ i ≤ n-1), make all the elements of the array from index 0 to i equal, using the minimum number of operations.

In one operation you either increase or decrease the array element by 1. Return an array that contains the minimum number of operations for each i, to accomplish the above task.

Note:  

For each index i, consider the original array without applying modifications made for previous indices.
Try to solve the problem using O(1) extra space (excluding the resultant array).
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> optimalArray(vector<int> &a) {
        int n = a.size();
        vector<int> ans(n);
  
        ans[0] = 0;
    
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + (a[i] - a[i / 2]);
        }
    
        return ans;
    }
};