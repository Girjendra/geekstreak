/*
Given an n × m binary matrix grid[][], find the total count of all cells containing 1 that are
unable to move out of the grid through a path of adjacent 1s.
Adjacency means you can only move in four directions: Up, Down, Left, and Right. Diagonal
moves are not allowed.
Assume that the space immediately outside the grid is an open path. Any 1 located directly on the
outer boundary of the grid (first row, last row, first column, or last column) can immediately step
out, and any 1 connected to it can follow and also step out of the grid.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>> &grid) {

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;
            
        grid[i][j] = 0;

        int rowDir[4] = {1, 0, -1, 0};
        int colDir[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++)
            dfs(i + rowDir[k], j + colDir[k], grid);
    }

    int cntOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
            
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfs(i, 0, grid);
            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(0, j, grid);
            if (grid[n - 1][j] == 1)
                dfs(n - 1, j, grid);
        }
    
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                count += grid[i][j];
        }
    
        return count;
    }
};