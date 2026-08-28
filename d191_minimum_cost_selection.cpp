/*
Given an n × 3 matrix mat[][], where each row represents the costs of three available choices at a shop, select exactly one choice from each row such that the same choice is not selected in two adjacent rows.

Return the minimum total cost required.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;



class Solution {
  public:
    int solve(int i, int prev, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        int n = mat.size();
    
        if (i == n)
            return 0;
            
        if (dp[i][prev] != -1)
            return dp[i][prev];
        
        int ans = INT_MAX;
        for (int choice = 0; choice < 3; choice++)
            if (choice != prev)
                ans = min(ans, mat[i][choice] + solve(i + 1, choice, mat, dp));
    
        return dp[i][prev] = ans;
    }
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        
        int one = mat[0][0] + solve(1, 0, mat, dp);
        int two = mat[0][1] + solve(1, 1, mat, dp);
        int three = mat[0][2] + solve(1, 2, mat, dp);
        
        return min({one, two, three});
    }
};