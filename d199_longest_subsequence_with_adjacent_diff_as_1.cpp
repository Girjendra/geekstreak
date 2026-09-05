/*
Given an array arr[] with n elements. find the longest subsequence such that the absolute difference between adjacent elements is one.
*/
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// TC : O(2^n) SC: O(n)
class Solution {
  public:
    int solve(int i, vector<int>& arr, int prev) {
        if(i == arr.size())
            return 0;
            
        int skip = solve(i + 1, arr, prev);
        
        int take = 0;
        if(prev == -1 || abs(prev - arr[i]) == 1)
            take = 1 + solve(i + 1, arr, arr[i]);
        
        return max(skip, take);
    }
    
    int longestSubseq(vector<int>& arr) {
        return solve(0, arr, -1);
    }
};



// TC : O(n^2) SC: O(n^2)
class Solution {
  public:
    int solve(int i, int prev, vector<int>& arr, vector<vector<int>>& dp) {
        if(i == arr.size())
            return 0;
            
        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];
            
        int skip = solve(i + 1, prev, arr, dp);
        
        int take = 0;
        if(prev == -1 || abs(arr[prev] - arr[i]) == 1)
            take = 1 + solve(i + 1, i, arr, dp);
    
        return dp[i][prev+1] = max(skip, take);
    }
    
    int longestSubseq(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, -1, arr, dp);
    }
};



// TC : O(n) SC: O(n)
class Solution {
  public:
     int longestSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int> dp;
        
        for(int x : arr) {
            dp[x] = max(dp[x-1], dp[x+1]) + 1;
            ans = max(ans, dp[x]);
        }
        
        return ans;
    }
};