/*
Given two machines, Machine A and Machine B, and a set of n tasks. The profit earned for performing
each task is given in two arrays a[] and b[] such that if Machine A performs the i-th task, the profit
is a[i], and if Machine B performs it, the profit is b[i].

Machine A can process at most x tasks, and Machine B can process at most y tasks. It is guaranteed that
x + y ≥ n, so all tasks can be assigned. Return the maximum possible profit after assigning each task to
either Machine A or Machine B.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();

        vector<vector<int>> diff(n, vector<int>(2));
        for (int i = 0; i < n; i++)
            diff[i] = {abs(a[i] - b[i]), i};

        sort(diff.begin(), diff.end(), greater<vector<int>>());
    
        int ans = 0;
        int i = 0;
    
        while (i < n && x > 0 && y > 0) {
            int index = diff[i][1];
    
            if (a[index] >= b[index]) {
                ans += a[index];
                x--;
            }
            else {
                ans += b[index];
                y--;
            }
            
            i++;
        }
    
        while (i < n && x > 0) {
            int index = diff[i][1];
            ans += a[index];
            x--;
            i++;
        }
    
        while (i < n && y > 0) {
            int index = diff[i][1];
            ans += b[index];
            y--;
            i++;
        }
    
        return ans;
    }
};





//  TC = O(n*x*y) SC = O(n*x*y)
class Solution {
  public:
    int solve(int i, int x, int y, vector<int> &a, vector<int> &b, vector<vector<vector<int>>>& dp) {
        if (i < 0)
            return 0;

        if(dp[i][x][y] != -1)
            return dp[i][x][y];
            
        if (x > 0 && y > 0) {
            int takeA = a[i] + solve(i - 1, x - 1, y, a, b, dp);
    
            int takeB = b[i] + solve(i - 1, x, y - 1, a, b, dp);
    
            return dp[i][x][y] = max(takeA, takeB);
        }

        if (y == 0)
            return dp[i][x][y] = a[i] + solve(i - 1, x - 1, y, a, b, dp);

        return dp[i][x][y] = b[i] + solve(i - 1, x, y - 1, a, b, dp);
    }
    
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(x+1, vector<int>(y+1, -1)));
        return solve(n - 1, x, y, a, b, dp);
    }
};