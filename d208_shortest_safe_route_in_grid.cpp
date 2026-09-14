/*
Given a 2D matrix mat[][] of size n × m, where each cell is either 0 (landmine) or 1 (safe), find the minimum number of steps required to travel from any cell in the leftmost column to any cell in the rightmost column.

You can move only in four directions: up, down, left, and right.
A cell is unsafe if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells must be avoided.
Return -1 if no safe path exists.

*/

#include<iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;



class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &mat,
            vector<vector<int>>& vis) {

        int n = mat.size();
        int m = mat[0].size();

        if(mat[i][j] == 0 || vis[i][j])
            return INT_MAX;

        if((i > 0 && !mat[i-1][j]) ||
            (i < n-1 && !mat[i+1][j]) ||
            (j > 0 && !mat[i][j-1]) ||
            (j < m-1 && !mat[i][j+1]))
            return INT_MAX;

        if(j == m-1)
            return 1;

        vis[i][j] = true;

        int left = INT_MAX;
        int right = INT_MAX;
        int up = INT_MAX;
        int down = INT_MAX;

        int temp;

        if(j > 0 && mat[i][j-1] == 1) {
            temp = solve(i, j-1, mat, vis);
            if(temp != INT_MAX)
                left = 1 + temp;
        }

        if(j < m-1 && mat[i][j+1] == 1) {
            temp = solve(i, j+1, mat, vis);
            if(temp != INT_MAX)
                right = 1 + temp;
        }

        if(i > 0 && mat[i-1][j] == 1) {
            temp = solve(i-1, j, mat, vis);
            if(temp != INT_MAX)
                up = 1 + temp;
        }

        if(i < n-1 && mat[i+1][j] == 1) {
            temp = solve(i+1, j, mat, vis);
            if(temp != INT_MAX)
                down = 1 + temp;
        }

        vis[i][j] = false;   // backtrack

        return min(min(left, right), min(up, down));
    }

    int shortestPath(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {

            if(mat[i][0] == 0)
                continue;

            vector<vector<int>> vis(n, vector<int>(m, false));

            ans = min(ans, solve(i, 0, mat, vis));
        }

        return ans != INT_MAX ? ans : -1;
    }
};





class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> safe(n, vector<int>(m, 1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    safe[i][j] = 0;

                    if(i > 0) safe[i-1][j] = 0;
                    if(i < n-1) safe[i+1][j] = 0;
                    if(j > 0) safe[i][j-1] = 0;
                    if(j < m-1) safe[i][j+1] = 0;
                }
            }
        }

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            if(safe[i][0]) {
                q.push({i, 0});
                dist[i][0] = 1;
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(c == m-1)
                return dist[r][c];

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    safe[nr][nc] &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};