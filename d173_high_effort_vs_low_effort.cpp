/*
Given two integer arrays h[] and l[], where h[i] and l[i] denote the number of tasks that can be completed on the i-th day by performing a high-effort task and a low-effort task, respectively.

For each day, you may choose exactly one of the following:

Perform no task.
Perform a low-effort task.
Perform a high-effort task, which can only be performed on the first day or if no task was performed on the previous day.
Return the maximum total number of tasks that can be completed over all days.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int solve(int i, int ishet, vector<int>& h, vector<int>& l,
                vector<vector<int>>& dp) {
        if(i == h.size())
            return 0;
            
        if(dp[i][ishet] != -1)
            return dp[i][ishet];
            
        int no = solve(i+1, 0, h, l, dp);
        int let = l[i] + solve(i+1, 1, h, l, dp);
        
        int het = 0;
        if(!ishet)
            het = h[i] + solve(i+1, 1, h, l, dp);
            
        return dp[i][ishet] = max({no, let, het});
    }
    
    int maxTask(vector<int>& h, vector<int>& l) {
        vector<vector<int>> dp(h.size()+1, vector<int>(2, -1));
        
        return solve(0, 0, h, l, dp);
    }
};