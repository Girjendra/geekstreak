/*
Given a matrix mat[][] of size n x m, where mat[i][j] represents the signal strength of a communication tower. Two control stations monitor the network:

Station P covers the top and left boundaries of the grid.
Station Q covers the bottom and right boundaries of the grid.
A signal can propagate from a tower to one of its neighbouring towers in the four directions (North, South, East, and West) only if the neighbouring tower has a signal strength less than or equal to that of the current tower.

Determine the number of towers (x, y) from which a signal can eventually reach both Station P and Station Q. Any tower located on a boundary covered by a station can transmit directly to that station.
*/
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    
    void bfs(vector<vector<int>> &strength, int n, int m, queue<pair<int, int>> &q,
             vector<vector<bool>> &reachable) {
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
    
            for (int k = 0; k < 4; k++) {
                int newRow = row + dx[k];
                int newCol = col + dy[k];
    
                if (isValid(newRow, newCol, n, m) && !reachable[newRow][newCol] &&
                    strength[newRow][newCol] >= strength[row][col]) {
    
                    reachable[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
    
        queue<pair<int, int>> stationP, stationQ;
    
        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
    
        for (int j = 0; j < m; j++) {
            stationP.push({0, j});
            reachP[0][j] = true;
    
            stationQ.push({n - 1, j});
            reachQ[n - 1][j] = true;
        }
    
        for (int i = 0; i < n; i++) {
            stationP.push({i, 0});
            reachP[i][0] = true;
    
            stationQ.push({i, m - 1});
            reachQ[i][m - 1] = true;
        }
    
        bfs(mat, n, m, stationP, reachP);
        bfs(mat, n, m, stationQ, reachQ);
    
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                if (reachP[i][j] && reachQ[i][j])
                    count++;
                
            }
        }
    
        return count;
    }
};