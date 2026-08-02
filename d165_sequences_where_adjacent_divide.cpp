/*
Given two positive integer n and m. Find the number of arrays of size n that can be formed such that:

Each element is in the range [1, m].
All adjacent are such that one of them divide the another i.e element Ai divides Ai + 1 or Ai+1 divides Ai.
*/
#include<iostream>
#include <vector>
using namespace std;

//  TC = O(m^n) and SC = O(n)
class Solution {
  public:
    int mod = 1e9 + 7;
    int solve(int val, int cnt, int n, int m) {
        if (cnt == n)
            return 1;

        int res = 0;
        for (int i = 1; i <= m; i++) {
            if ((i % val == 0)  || (val % i == 0))
                res = (res + solve(i, cnt + 1, n, m)) % mod;
        }
    
        return res % mod;
    }
    
    int count(int n, int m) {
        return solve(1, 0, n, m);
    }
};


// TC = O(n * m * m) and SC = O(n * m)
class Solution {
  public:
    int mod = 1e9 + 7;
    int solve(int val, int cnt, int n, int m, vector<vector<int>>& dp) {
        if (cnt == n)
            return 1;

        if(dp[val][cnt] != -1)
            return dp[val][cnt];
            
        int res = 0;
        for (int i = 1; i <= m; i++) {
            if ((i % val == 0)  || (val % i == 0))
                res = (res + solve(i, cnt + 1, n, m, dp)) % mod;
        }
    
        return dp[val][cnt] = (res % mod);
    }
    int count(int n, int m) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solve(1, 0, n, m, dp);
    }
};