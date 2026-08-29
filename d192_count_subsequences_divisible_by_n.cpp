/*
Given a numeric string s containing only digits and an integer n, count the number of non-empty subsequences of s whose numeric value is divisible by n. Return the answer modulo 1e9 + 7.
*/
#include<iostream>
#include <vector>
using namespace std;

// TC : O(m * n * 2) = O(m * n)
class Solution {
  public:
    int solve(int idx, int rem, bool started, string &s, int n, int MOD, vector<vector<vector<int>>> &dp) {
        if (idx == s.size())
            return (started && rem == 0) ? 1 : 0;
    
        if (dp[idx][rem][started] != -1)
            return dp[idx][rem][started];
    
        int ans = 0;
    
        ans = (ans + solve(idx + 1, rem, started, s, n, MOD, dp)) % MOD;
    
        int digit = s[idx] - '0';
        int newRem;
    
        if (!started)
            newRem = digit % n;
        else
            newRem = (rem * 10 + digit) % n;
    
        ans = (ans + solve(idx + 1, newRem, true, s, n, MOD, dp)) % MOD;
    
        return dp[idx][rem][started] = ans;
    }
    
    int countSubsequences(string& s, int n) {
        int m = s.size();
    
        int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
    
        return solve(0, 0, false, s, n, MOD, dp);
    }
};



// TC : O(m * n * 2) = O(m * n)
class Solution {
  public:
    int countSubsequences(string& s, int n) {
        int m = s.size();
        int MOD = 1e9 + 7;
    
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n, vector<int>(2, 0)));
    
        for (int rem = 0; rem < n; rem++) {
            dp[m][rem][0] = 0;
            dp[m][rem][1] = (rem == 0);
        }
    
        for (int idx = m - 1; idx >= 0; idx--) {
            int digit = s[idx] - '0';
    
            for (int rem = 0; rem < n; rem++) {
                for (int started = 0; started <= 1; started++) {
                    int ans = 0;
    
                    ans = (ans + dp[idx + 1][rem][started]) % MOD;
    
                    int newRem;
    
                    if (!started)
                        newRem = digit % n;
                    else
                        newRem = (rem * 10 + digit) % n;
    
                    ans = (ans + dp[idx + 1][newRem][1]) % MOD;
    
                    dp[idx][rem][started] = ans;
                }
            }
        }
    
        return dp[0][0][0];
    }
};



// TC : O(m * n) = O(m * n)
class Solution {
  public:
    int countSubsequences(string& s, int n) {
        int MOD = 1e9 + 7;
    
        vector<int> dp(n, 0);
    
        for (char ch : s) {
            int digit = ch - '0';
    
            vector<int> curr(dp);
    
            curr[digit % n] = (curr[digit % n] + 1) % MOD;
    
            for (int rem = 0; rem < n; rem++) {
                int newRem = (rem * 10 + digit) % n;
                curr[newRem] = (curr[newRem] + dp[rem]) % MOD;
            }
    
            dp = curr;
        }
    
        return dp[0];
    }
};