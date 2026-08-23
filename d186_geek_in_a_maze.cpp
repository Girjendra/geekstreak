/*
Given a maze mat[][] of size n × m, where each cell is either:

'.' representing an empty cell, or
'#' representing an obstacle.
Find the number of distinct empty cells that Geek can visit starting from the cell (r, c).

Geek can move up, down, left, or right to an adjacent non-obstacle cell inside the maze.
On any path, Geek can make at most u upward moves and d downward moves.
There is no limit on the number of left or right moves.
If the starting cell is an obstacle, return 0.
Note :  There can be multiple paths starting from [r, c].
*/
#include<iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// TC = O(n*m), SC = O(n*m)
class Solution {
public:
    int numberOfCells(int r, int c, int u, int d,
                      vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        if(mat[r][c] == '#')
            return 0;

        // Minimum UP moves used to reach each cell
        vector<vector<int>> upUsed(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;

        upUsed[r][c] = 0;
        q.push({r, c});

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            int currUp = upUsed[x][y];

            // downUsed = upUsed + row difference
            int currDown = currUp + (x - r);

            // UP
            if(x - 1 >= 0 &&
               mat[x-1][y] == '.' &&
               currUp + 1 <= u &&
               currUp + 1 < upUsed[x-1][y]) {

                upUsed[x-1][y] = currUp + 1;
                q.push({x-1, y});
            }

            // DOWN
            if(x + 1 < n &&
               mat[x+1][y] == '.' &&
               currDown + 1 <= d &&
               currUp < upUsed[x+1][y]) {

                upUsed[x+1][y] = currUp;
                q.push({x+1, y});
            }

            // LEFT
            if(y - 1 >= 0 &&
               mat[x][y-1] == '.' &&
               currUp < upUsed[x][y-1]) {

                upUsed[x][y-1] = currUp;
                q.push({x, y-1});
            }

            // RIGHT
            if(y + 1 < m &&
               mat[x][y+1] == '.' &&
               currUp < upUsed[x][y+1]) {

                upUsed[x][y+1] = currUp;
                q.push({x, y+1});
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(upUsed[i][j] != INT_MAX)
                    ans++;
            }
        }

        return ans;
    }
};