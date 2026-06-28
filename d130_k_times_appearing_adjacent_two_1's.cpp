/*
Given two integers n and k, count the number of binary strings of length n where adjacent 1 appear k times.

Since the answer can be huge, return it modulo 109+7.
*/
#include<iostream>
#include <cstring>
using namespace std;
class Solution {
  public:
    int mod = 1e9 + 7;
    int dp[1005][2][1005];

    int solve(int n, int prev, int cnt, int k) {
        if(n == 0)
            return (cnt == k);

        if(dp[n][prev][cnt] != -1)
            return dp[n][prev][cnt];

        int ans = solve(n - 1, 0, cnt, k);
        
        if(prev == 1)
            ans = (ans + solve(n - 1, 1, cnt + 1, k)) % mod;
        else
            ans = (ans + solve(n - 1, 1, cnt, k)) % mod;

        return dp[n][prev][cnt] = ans;
    }

    int countStrings(int n, int k) {
        memset(dp, -1, sizeof(dp));

        return (solve(n - 1, 0, 0, k) +
                solve(n - 1, 1, 0, k)) % mod;
    }
};