/*
Given an array arr[] of integers and an integer k, find a subsequence of size k whose product is maximum among all possible subsequences of size k. Return the maximum product that can be obtained.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;



// TC : O(2^n) SC : O(n)
class Solution {
  public:
    void solve(int i, vector<int>& arr, int k, int& ans, int cur) {
        if(i == arr.size() && k > 0)
            return ;
            
        if(k == 0) {
            ans = max(ans, cur);
            return ;
        }
            
        solve(i+1, arr, k, ans, cur);
        if(k > 0)
            solve(i+1, arr, k-1, ans, cur*arr[i]);
    }
    
    int maxProduct(vector<int> &arr, int k) {
        int ans = INT_MIN;
        solve(0, arr, k, ans, 1);
        
        return ans;
    }
};



// TC : O(2^n) SC : O(n)
class Solution {
public:
    pair<long long, long long> solve(int i, vector<int>& arr, int k) {
        if(k == 0)
            return {1, 1};

        if(i == arr.size() || arr.size() - i < k)
            return {LLONG_MIN, LLONG_MAX};

        auto skip = solve(i + 1, arr, k);

        auto take = solve(i + 1, arr, k - 1);

        long long mx = max(skip.first,
                           max(1LL * arr[i] * take.first,
                               1LL * arr[i] * take.second));
        
        long long mn = min(skip.second,
                           min(1LL * arr[i] * take.first,
                               1LL * arr[i] * take.second));

        return {mx, mn};
    }

    long long maxProduct(vector<int>& arr, int k) {
        return solve(0, arr, k).first;
    }
};




// TC : O(n*k) SC : O(n*k)
class Solution {
public:
    pair<long long, long long> solve(
        int i, vector<int>& arr, int k,
        vector<vector<pair<long long, long long>>>& dp,
        vector<vector<bool>>& vis) {

        if(k == 0)
            return {1, 1};

        if(i == arr.size() || arr.size() - i < k)
            return {LLONG_MIN, LLONG_MAX};

        if(vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        auto skip = solve(i + 1, arr, k, dp, vis);
        auto take = solve(i + 1, arr, k - 1, dp, vis);

        long long mx = skip.first;
        long long mn = skip.second;

        if(take.first != LLONG_MIN) {
            mx = max(mx, 1LL * arr[i] * take.first);
            mn = min(mn, 1LL * arr[i] * take.first);
        }

        if(take.second != LLONG_MAX) {
            mx = max(mx, 1LL * arr[i] * take.second);
            mn = min(mn, 1LL * arr[i] * take.second);
        }

        return dp[i][k] = {mx, mn};
    }

    long long maxProduct(vector<int>& arr, int k) {
        int n = arr.size();

        vector<vector<pair<long long, long long>>> dp(
            n + 1,
            vector<pair<long long, long long>>(k + 1)
        );

        vector<vector<bool>> vis(
            n + 1,
            vector<bool>(k + 1, false)
        );

        return solve(0, arr, k, dp, vis).first;
    }
};