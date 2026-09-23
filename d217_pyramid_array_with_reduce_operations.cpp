/*
Given an array arr[] consisting of stones, where arr[i] represents the height of the i-th stone.

You need to transform the stones into a pyramid by only reducing the heights of the stones. Reducing the height of a stone by 1 costs 1 unit, and stones cannot be increased or moved.
A valid pyramid consists of a contiguous subarray whose heights follow the pattern: 1, 2, 3, ..., x - 1, x, x - 1, ..., 2, 1 for some positive integer x.
Every stone outside this subarray must have a height of 0.

Find the minimum total cost required to build a pyramid. It is guaranteed that at least one valid pyramid can always be formed.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;




// TC : O(n) SC : O(n)
class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        int totalHeight = 0;
    
        for (int i = 0; i < n; i++)
            totalHeight += arr[i];
    
        if (n <= 2)
            return totalHeight - 1;
    
        vector<int> left(n), right(n);
    
        left[0] = 1;
        for (int i = 1; i < n; i++)
            left[i] = min(left[i - 1] + 1, arr[i]);
    
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            right[i] = min(right[i + 1] + 1, arr[i]);
    
        int minCost = INT_MAX;
    
        for (int i = 0; i < n; i++) {
            int peakHeight = min(left[i], right[i]);
    
            int pyramidSum = peakHeight * peakHeight;
    
            minCost = min(minCost, totalHeight - pyramidSum);
        }
    
        return minCost;
    }
};