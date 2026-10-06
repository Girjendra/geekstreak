/*
Given a matrix with n rows and m columns, find the length of the longest path such that:
The path can start and end at any cell.
A cell cannot be visited more than once.
The values in path are strictly increasing. 
From each cell,  you can move left, right, up, or down.
Diagonal moves and moves outside the matrix are not allowed.

Examples:
Input: n = 3, m = 3, matrix[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 5
Explanation: One such path is 1 -> 2 -> 3 -> 6 -> 9, where each number is strictly greater than the previous.

Input: n = 3, m = 3, matrix[][] = [[3, 4, 5], [6, 2, 6], [2, 2, 1]]
Output: 4
Explanation: One of the longest increasing paths is 3 -> 4 -> 5 -> 6.

Input: n = 2, m = 2, matrix[][] = [[1, 1], [1, 1]]
Output: 1
Explanation: There can at most one vertex as all vertices are same.

Constraints:
1 ≤ n, m ≤ 1000
0 ≤ matrix[i][j] ≤ 230
*/
#include<iostream>
#include <vector>
using namespace std;





// TC : O(n*m*4^(n*m)) SC: O(n*m)
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &mat, int n, int m) {      
        vector<vector<int>> mov = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int ans = 1;
        for(auto it : mov) {
            int ni = i + it[0];
            int nj = j + it[1];
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] > mat[i][j])
                ans = max(ans, 1 + solve(ni, nj, mat, n, m));
        }
        
        return ans;
    }
    
    int longIncPath(vector<vector<int>> &mat, int n, int m) {
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, mat, n, m));
            }
        }
        
        return ans;
    }
};





// TC : O(n^2*m^2) SC: O(n*m)
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &mat, int n, int m, vector<vector<int>>& dp) {   
        vector<vector<int>> mov = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans = 1;
        for(auto it : mov) {
            int ni = i + it[0];
            int nj = j + it[1];
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] > mat[i][j])
                ans = max(ans, 1 + solve(ni, nj, mat, n, m, dp));
        }
        
        return  dp[i][j] = ans;
    }
    
    int longIncPath(vector<vector<int>> &mat, int n, int m) {
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<vector<int>> dp(n, vector<int>(m, -1));
                ans = max(ans, solve(i, j, mat, n, m, dp));
            }
        }
        
        return ans;
    }
};









// TC : O(n*m + n*m) = O(2n*m) = O(n*m)  SC: O(n*m)
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &mat, int n, int m, vector<vector<int>>& dp) {
        vector<vector<int>> mov = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans = 1;
        for(auto it : mov) {
            int ni = i + it[0];
            int nj = j + it[1];
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] > mat[i][j])
                ans = max(ans, 1 + solve(ni, nj, mat, n, m, dp));
        }
        
        return  dp[i][j] = ans;
    }
    
    int longIncPath(vector<vector<int>> &mat, int n, int m) {
        int ans = 0;
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, mat, n, m, dp));
            }
        }
        
        return ans;
    }
};