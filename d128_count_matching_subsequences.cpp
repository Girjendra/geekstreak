/*
Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.

Return the total count modulo 1e9+7.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
  int mod = 1e9 + 7;
  int solve(string &s1, string &s2, int i, int j, vector<vector<int>>& dp) {
        if (j == s2.size())
            return 1;
        
        if (i == s1.size())
            return 0;
    
        if(dp[i][j] != -1)
            return dp[i][j];
            
        long long ans = solve(s1, s2, i + 1, j, dp);
    
        if (s1[i] == s2[j])
            ans += solve(s1, s2, i + 1, j + 1, dp);
    
        return dp[i][j] =  (ans % mod);
    }
    
    int countWays(string &s1, string &s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};
