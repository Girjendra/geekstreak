/*
Given two arrays a[] and b[] of positive integers of size n and m respectively, where m ≤ n.  You are allowed to insert zeros anywhere into the second array b so that its length becomes equal to n.

The dot product of two arrays of equal length n is defined as: a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].
Return the maximum possible dot product of the two arrays.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int solve(int i, int j, vector<int> &a, vector<int> &b, vector<vector<int>>& dp) {
        if (j == b.size())
            return 0;
            
        if (i == a.size())
            return -1e9;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int match = (a[i] * b[j]) + solve(i + 1, j + 1, a, b, dp);
        int skip = solve(i + 1, j, a, b, dp);
    
        return dp[i][j] = max(match, skip);
    }

    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return solve(0, 0, a, b, dp);
    }
};
