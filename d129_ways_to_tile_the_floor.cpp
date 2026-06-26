/*
Given a floor of dimensions n × m and an unlimited supply of tiles of size 1 × m, find the total number of ways to completely tile the floor.
Each tile can be placed in one of the following ways:

Horizontally, covering 1 row and m columns.
Vertically, covering m rows and 1 column.
Count all possible ways to cover the entire floor such that there are no overlaps and no uncovered cells.

Since the number of possible tilings can be very large, return the answer modulo 109+7.

Note: n and m are positive integers, and m ≥ 2.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int solve(int n, int m, vector<int>& dp) {
        int MOD = 1000000007;
    
        if (n < m)
            return 1;
    
        if (n == m)
            return 2;
   
        if (dp[n] != -1)
            return dp[n];
    
        return dp[n] = (solve(n - 1, m, dp) + solve(n - m, m, dp)) % MOD;
    }

    int countWays(int n, int m) {
        vector<int> dp(n + 1, -1);

        return solve(n, m, dp);
    }
};