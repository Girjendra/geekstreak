/*
Given four integers n, i, d, and c, where:

i is the cost of inserting a single character,
d is the cost of deleting the last character,
c is the cost of copying the entire current string and pasting it immediately (thereby doubling its length).
Find the minimum cost required to obtain exactly n characters on the screen. Initially, the screen is empty.
*/
#include<iostream>
#include <vector>
using namespace std;


// TC : O(2^n) SC : O(n)
class Solution {
public:
    int solve(int n, int i, int d, int c, int l) {
        if(l == 0)
            return 0;

        if(l == 1)
            return i;

        int ans = solve(n, i, d, c, l - 1) + i;

        if(l % 2 == 0)
            ans = min(ans, solve(n, i, d, c, l / 2) + c);
        else
            ans = min(ans, solve(n, i, d, c, (l + 1) / 2) + c + d);

        return ans;
    }

    int minCost(int n, int i, int d, int c) {
        return solve(n, i, d, c, n);
    }
};



// TC : O(n) SC : O(n)
class Solution {
public:
    int solve(int n, int i, int d, int c, int l, vector<int>& dp) {
        if(l == 0)
            return 0;

        if(l == 1)
            return i;

        if(dp[l] != -1)
            return dp[l];

        int ans = solve(n, i, d, c, l - 1, dp) + i;

        if(l % 2 == 0)
            ans = min(ans, solve(n, i, d, c, l / 2, dp) + c);
        else
            ans = min(ans, solve(n, i, d, c, (l + 1) / 2, dp) + c + d);

        return dp[l] = ans;
    }

    int minCost(int n, int i, int d, int c) {
        vector<int> dp(n + 1, -1);
        return solve(n, i, d, c, n, dp);
    }
};