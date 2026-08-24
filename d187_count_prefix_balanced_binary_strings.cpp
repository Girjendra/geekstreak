/*
Given an integer n, count the number of binary strings of length 2 * n that contain exactly n ones and n zeros such that every prefix of the string contains at least as many ones as zeros. Since the answer can be very large, return it modulo 109 + 7.
*/
#include<iostream>
#include <vector>
using namespace std;

// TC : O(2^(2*n)) SC : O(n)
class Solution {
  public:
    int MOD = 1e9+7;
    int solve(int n, int zero, int one) {
        if(one == n && zero == n)
            return 1;
            
        int ans = 0;
        if(zero < one)
            ans += solve(n, zero+1, one) % MOD;
            
        if(one < n) 
            ans += solve(n, zero, one+1) % MOD;
            
        return ans % MOD;
    }
    int prefixStrings(int n) {
        return solve(n, 0, 0);
    }
};


// TC : O(n^2) SC : O(n^2)
class Solution {
  public:
    int MOD = 1e9+7;
    int solve(int n, int zero, int one,vector<vector<int>>& dp) {
        if(one == n && zero == n)
            return 1;
        
        if(dp[zero][one] != -1)
            return dp[zero][one];
            
        int ans = 0;
        if(zero < one)
            ans += solve(n, zero+1, one, dp) % MOD;
            
        if(one < n) 
            ans += solve(n, zero, one+1, dp) % MOD;
            
        return dp[zero][one] = (ans % MOD);
    }
    int prefixStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solve(n, 0, 0, dp);
    }
};



// TC : O(n) SC : O(n)
class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long ans = 1;

        while(b) {
            if(b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    int prefixStrings(int n) {
        vector<long long> fact(2 * n + 1);

        fact[0] = 1;

        for(int i = 1; i <= 2 * n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        long long ans = fact[2 * n];

        ans = ans * power(fact[n], MOD - 2) % MOD;
        ans = ans * power(fact[n], MOD - 2) % MOD;
        ans = ans * power(n + 1, MOD - 2) % MOD;

        return ans;
    }
};