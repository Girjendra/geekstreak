/*
Given an integer array arr[], you are allowed to replace any elements with 1.  Find the maximum sum of absolute differences between consecutive elements after any number of modifications.
*/
#include<iostream>
#include <vector>
using namespace std;



// TC : O(2^n) SC: O(n)
class Solution {
  public:
    void solve(int i, vector<int>& arr, long long sum, long long& ans) {
        int n = arr.size();

        if(i == n) {
            ans = max(ans, sum);
            return;
        }

        solve(i + 1, arr, sum, ans);

        long long newSum = sum;

        if(i > 0)
            newSum -= abs(arr[i] - arr[i - 1]);

        if(i < n - 1)
            newSum -= abs(arr[i] - arr[i + 1]);

        int old = arr[i];
        arr[i] = 1;

        if(i > 0)
            newSum += abs(arr[i] - arr[i - 1]);

        if(i < n - 1)
            newSum += abs(arr[i] - arr[i + 1]);

        solve(i + 1, arr, newSum, ans);

        arr[i] = old;
    }
    
    int maxDiffSum(vector<int>& arr) {
        long long sum = 0;
        for(int i = 1; i < arr.size(); i++)
            sum += abs(arr[i] - arr[i - 1]);

        long long ans = 0;
        solve(0, arr, sum, ans);
        
        return ans;
    }
};




// TC : O(n) SC: O(n)
class Solution {
  public:
    long long solve(int i, vector<int>& arr, int prev, vector<vector<long long>>& dp) {
        int n = arr.size();
        if(i == n)
            return 0;

        if(dp[i][prev] != -1)
            return dp[i][prev];

        int prevVal = (prev == 0 ? arr[i - 1] : 1);

        long long notChange =
            abs(arr[i] - prevVal) +
            solve(i + 1, arr, 0, dp);

        long long change =
            abs(1 - prevVal) +
            solve(i + 1, arr, 1, dp);

        return dp[i][prev] = max(notChange, change);
    }
    
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1)
            return 0;

        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        long long notChange = solve(1, arr, 0, dp);
        long long change = solve(1, arr, 1, dp);

        return max(notChange, change);
    }
};