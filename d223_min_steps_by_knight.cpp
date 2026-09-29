/*
Given a square chessboard of size n × n, the initial position knightPos and target position targetPos of a Knight are given. Find the minimum number of moves required for the Knight to reach targetPos.
A Knight moves in an L-shape, covering 2 cells in one direction and 1 cell perpendicular to it. From (x, y), it can move to: (x ± 2, y ± 1) and (x ± 1, y ± 2)
This gives at most 8 possible moves:
Note: The positions are given using 1-based indexing.

Examples:
Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
Output: 1
Explanation: Knight takes 1 step to reach from (3, 3) to (1 ,2).
Input: n = 6, knightPos[] = [1, 3], targetPos[] = [5, 1]
Output: 2
Explanation: In above diagram Knight takes 2 step to reach from (1, 3) to (5, 0): (1, 3) -> (3, 2) -> (5, 1)  

Constraints:
n ≤ 1000
2 ≤ knightPos.size(), targetPos.size() ≤ 2
1 ≤ knightPos[i], targetPos[i] ≤ n
*/
#include<iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;





// TC : O(8^(n^2)) SC : O(n^2)
class Solution {
public:
    int solve(int n, int i, int j, int ti, int tj, vector<vector<int>>& pos, vector<vector<bool>>& vis) {
        if(i >= n || j >= n || i < 0 || j < 0 || vis[i][j])
            return INT_MAX;
            
        if(i == ti && j == tj)
            return 0;
        
        vis[i][j] = true;
        
        int temp = INT_MAX;
        int ans = INT_MAX;
        for(auto it : pos) {
            int ni = i + it[0];
            int nj = j + it[1];

            temp = solve(n, ni, nj, ti, tj, pos, vis);
            if(temp != INT_MAX)
                ans = min(ans, temp + 1);
        }
        
        vis[i][j] = false;
        return ans;
    }
    
    int minStepToReachTarget(vector<int>& kp, vector<int>& tp, int n) {
        vector<vector<int>> pos = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        kp[0]--;
        kp[1]--;
        tp[0]--;
        tp[1]--;
            
        return solve(n, kp[0], kp[1], tp[0], tp[1], pos, vis);
    }
};





// TC : O(n^2) SC : O(n^2)
class Solution {
public:
    int minStepToReachTarget(vector<int>& kp, vector<int>& tp, int n) {
        vector<vector<int>> moves = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        kp[0]--;
        kp[1]--;
        tp[0]--;
        tp[1]--;
        
        int si = kp[0];
        int sj = kp[1];
        int ti = tp[0];
        int tj = tp[1];
        
        queue<pair<int, int>> q;
        q.push({si, sj});
        dp[si][sj] = 0;
        
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            if(i == ti && j == tj)
                return dp[ti][tj];
                
            for(auto mov : moves) {
                int ni = i + mov[0];
                int nj = j + mov[1];
                
                if(ni >= 0 && ni < n && nj >= 0 && nj < n && dp[ni][nj] == -1) {
                    dp[ni][nj] = dp[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        
        return -1;
    }
};




// TC : O(n^2) SC : O(n^2)
class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int x = knightPos[0] - 1;
        int y = knightPos[1] - 1;
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({{x, y}, 0});
        visited[x][y] = true;

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;

            q.pop();

            if (x == tx && y == ty)
                return steps;

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    !visited[nx][ny]) {

                    visited[nx][ny] = true;
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }

        return -1;
    }
};