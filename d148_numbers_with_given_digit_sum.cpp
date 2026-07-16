/*
Given two integers n and sum, determine the number of n-digit positive integers whose digits add up to sum.

An n-digit number cannot have leading zeros; that is, the first digit must be between 1 and 9.
If there exist no n digit number with sum of digits equal to given sum, return -1.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int solve(int n, int cs, vector<vector<int>> &dp) {
        if (n == 0)
            return cs == 0;
        
        if (cs == 0)
            return 1;
    
        if (dp[n][cs] != -1)
            return dp[n][cs];
            
        int ans = 0;
        for(int i = 0; i <= 9; i++)
            if (cs - i >= 0)
                ans += solve(n-1, cs-i, dp);
        
        return dp[n][cs] = ans;
    }
    
    int countWays(int n, int sum) {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        for(int i = 1; i <= 9; i++) {
            if(sum - i >= 0)
                ans += solve(n-1, sum-i, dp);
        }
        
        if(ans == 0)
            return -1;
            
        return ans;
    }
};