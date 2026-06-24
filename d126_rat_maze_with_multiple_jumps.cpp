/*
Given a matrix mat[][] of size n × n, where mat[i][j] represents the maximum number of steps a rat can jump either forward (right) or downward from that cell, find a path for the rat to reach from the top-left cell (0, 0) to the bottom-right cell (n - 1, n - 1). A cell containing 0 is blocked and cannot be used in the path. It is guaranteed that the cell mat[n-1][n-1] is not 0.

Return an n × n matrix where 1 represents the cells included in the path and 0 represents the remaining cells. If no valid path exists, return [[-1]].

Note: If multiple valid paths exist, choose the path with the shortest possible jumps first. For the same jump length, moving forward (right) should be preferred over moving downward.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &ans, vector<vector<int>> &dp) {
        int n = mat.size();

        if (i >= n || j >= n || mat[i][j] == 0)
            return false;

        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }
    
        if (dp[i][j] != -1)
            return dp[i][j];
    
        ans[i][j] = 1;
        int jump = mat[i][j];

        for (int step = 1; step <= jump; step++) {
            if (solve(i, j + step, mat, ans, dp)) {
                return dp[i][j] = 1;
            }

            if (solve(i + step, j, mat, ans, dp)) {
                return dp[i][j] = 1;
            }
        }
    
        ans[i][j] = 0;
        return dp[i][j] = 0;
    }
    
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();

        if (n == 1)
            return {{1}};
    
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if (mat[0][0] == 0)
            return {{-1}};
    
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if (!solve(0, 0, mat, ans, dp))
            return {{-1}};
    
        return ans;
    }
};