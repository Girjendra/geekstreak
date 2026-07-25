/*
Given a n × n grid mat[][] of integers where values can be negative, find the maximum sum among all possible k × k sub-grids.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int res = INT_MIN;
    
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                int sum = 0;
    
                for (int r = i; r < i + k; r++)
                    for (int c = j; c < j + k; c++)
                        sum += mat[r][c];
    
                res = max(res, sum);
            }
        }
        
        return res;
    }
};


class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
    
        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                pre[i][j] = mat[i - 1][j - 1] + pre[i - 1][j]
                + pre[i][j - 1] - pre[i - 1][j - 1];
    
        int res = INT_MIN;
        for (int i = k; i <= n; i++)
            for (int j = k; j <= n; j++) {
                int sum = pre[i][j] - pre[i - k][j] - pre[i][j - k]
                + pre[i - k][j - k];
                res = max(res, sum);
            }
        
        return res;
    }
};