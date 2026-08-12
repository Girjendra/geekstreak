/*
Given a maze represented as an n x n grid, grid[][], using 0-based indexing. Each cell contains one of the values 1, 2, or 3, which determines the direction(s) you are allowed to move from that cell:

1 - you may move Right only.
2 - you may move Down only.
3 - you may move Right or Down (both directions are available).
You start at the top-left cell (0, 0) (the Entry) and must reach the bottom-right cell (n-1, n-1) (the Exit), following the movement rule of each cell you pass through. You are never allowed to move outside the boundaries of the grid.

The Adventure of a path is the sum of the values of all cells visited along that path (including both the entry and exit cells).

Find the total number of distinct valid paths from Entry to Exit, and among all such paths, the maximum possible Adventure. Return the answer as [totalPaths, maxAdventure].

Note: Return totalPaths modulo 109 + 7, maxAdventure needs no modulo, as it stays small regardless of grid size.
*/
#include<iostream>
#include <vector>
using namespace std;

// TC = O(2^(n²)) SC = O(n)
class Solution {
  public:
    int solve(int r, int c, vector<vector<int>>& grid, int curcost, int& maxcost) {
        int n = grid.size();
        
        if(r >= n || c >= n)
            return 0;
            
        if(r == n-1 && c == n-1) {
            maxcost = max(maxcost, curcost+grid[r][c]);
            return 1;
        }
        
        int ans = 0;
        if(grid[r][c] == 1)
            ans = solve(r, c+1, grid, curcost+1, maxcost);
        
        if(grid[r][c] == 2)
            ans += solve(r+1, c, grid, curcost+2, maxcost);
        
        if(grid[r][c] == 3) {
            ans += solve(r, c+1, grid, curcost+3, maxcost);
            ans += solve(r+1, c, grid, curcost+3, maxcost);
        }
        
        return ans;
    }
    
    vector<int> findWays(vector<vector<int>>& grid) {
        int maxcost = -1;
        int ans = solve(0, 0, grid, 0, maxcost);
        if(maxcost == -1)
            maxcost = 0;
            
        return {ans, maxcost};
    }
};


// TC = O(n²) SC = O(n²)
class Solution {
  public:
    int mod = 1e9 + 7;
    pair<int,int> solve(int r, int c, vector<vector<int>>& grid,
                            vector<vector<pair<int,int>>>& dp) {
        int n = grid.size();
        
        if(r >= n || c >= n)
            return {0, -1};
            
        if(dp[r][c].first != -1)
            return dp[r][c];
            
        if(r == n-1 && c == n-1)
            return dp[r][c] = {1, grid[r][c]};
        
        int paths = 0;
        int maxcost = -1;
        
        if(grid[r][c] == 1 || grid[r][c] == 3) {
            auto ans = solve(r, c+1, grid, dp);
            
            paths = (paths + ans.first) % mod;
            
            if(ans.second != -1)
                maxcost = max(maxcost, ans.second + grid[r][c]);
        }
        
        if(grid[r][c] == 2 || grid[r][c] == 3) {
            auto ans = solve(r+1, c, grid, dp);
            
            paths = (paths + ans.first) % mod;
            
            if(ans.second != -1)
                maxcost = max(maxcost, ans.second + grid[r][c]);
        }
        
        return dp[r][c] = {paths, maxcost};
    }
    
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1, -1}));
        
        int maxcost = -1;
        auto ans = solve(0, 0, grid, dp);
        if(ans.first == 0)
            return {0, 0};
            
        return {ans.first, ans.second};
    }
};