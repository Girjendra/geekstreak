/*
Given a binary matrix mat[][] of size n × m containing values 0 and 1, and four integers xs, ys, xd, and yd representing the source cell (xs, ys) and destination cell (xd, yd), find the length of the longest possible path from the source cell to the destination cell. From any cell, you can move to its adjacent cells in the up, down, left, and right directions.

1 represents a traversable cell.
0 represents a blocked cell that cannot be visited.
A cell can be visited at most once in a path.
If the destination cannot be reached from the source, return -1.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, 
                                int j, int x, int y) {
        int m = mat.size();
        int n = mat[0].size();
        
        if (i == x && j == y)
            return 0;
        
        if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == 0 || visited[i][j])
            return -1; 
        
        visited[i][j] = true;
        int maxPath = -1;
        
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];
            
            int pathLength = dfs(mat, visited, ni, nj, x, y);
            
            if (pathLength != -1)
                maxPath = max(maxPath, 1 + pathLength);
        }
        
        visited[i][j] = false;
        return maxPath;
    }

    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        int m = mat.size();
        int n = mat[0].size();
        
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(mat, visited, xs, ys, xd, yd);
    }
};