/*
Given a square matrix mat[][] of size n × n. A zigzag sequence starts from the top and ends at the bottom. Two consecutive elements of sequence cannot belong to the same column.

Return the maximum sum of such a zigzag sequence.
*/
#include<iostream>
#include <vector>
using namespace std;

// Brute Force Approach
// TC : O(n^n), SC : O(n)
class Solution {
  public:
    int findMaxZigzagSum(vector<vector<int>> &mat, int row, int prevCol) {
        int n = mat.size();
        
        if (row == n)
            return 0;
    
        int res = 0;
        for (int col = 0; col < n; col++)
            if (col != prevCol)
                res = max(res, mat[row][col] + findMaxZigzagSum(mat, row + 1, col));
    
        return res;
    }

    int zigzagSequence(vector<vector<int>>& mat) {
        return findMaxZigzagSum(mat, 0, -1);
    }
};

// Dynamic Programming Approach
// TC : O(n^2), SC : O(n^2)
class Solution {
  public:
    int findMaxZigzagSum(vector<vector<int>> &mat, int row, int prevCol,
            vector<vector<int>>& dp) {
        int n = mat.size();
        
        if (row == n)
            return 0;
    
        if(dp[row][prevCol] != -1)
            return dp[row][prevCol];
            
        int res = 0;
        for (int col = 0; col < n; col++)
            if (col != prevCol)
                res = max(res, mat[row][col] + findMaxZigzagSum(mat, row + 1, col, dp));
    
        return dp[row][prevCol] = res;
    }

    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return findMaxZigzagSum(mat, 0, n, dp);
    }
};