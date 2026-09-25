/*
Given three arrays height[], width[], and length[] of size n, where height[i], width[i], and length[i] represent the dimensions of the ith box, find the maximum possible height of a stack formed using these boxes.
A box can be rotated so that any of its dimensions becomes its height.
 A box can be placed on top of another only if both dimensions of its base are strictly smaller than those of the box below. 
Multiple instances of the same box can be used.
Examples:

Constraints:
1 ≤ height.size(), width.size(), length.size() ≤ 100
1 ≤ height[i], width[i], length[i] ≤ 106
*/
#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;




// TC : O(n^2) SC: O(n^2)
class Solution {
public:
    int solve(int i, int prev, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if(i == arr.size())
            return 0;

        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int take = INT_MIN;

        if(prev == -1 || (arr[i][0] < arr[prev][0] &&
            arr[i][1] < arr[prev][1])) {

            int temp = solve(i + 1, i, arr, dp);
            take = temp + arr[i][2];
        }

        int skip = solve(i + 1, prev, arr, dp);
        return dp[i][prev + 1] = max(take, skip);
    }

    int maxHeight(vector<int> &h, vector<int> &w, vector<int> &l) {
        vector<vector<int>> arr;
        int n = h.size();

        for(int i = 0; i < n; i++) {
            arr.push_back({max(l[i], w[i]), min(l[i], w[i]), h[i]});
            arr.push_back({max(l[i], h[i]), min(l[i], h[i]), w[i] });
            arr.push_back({max(w[i], h[i]), min(w[i], h[i]), l[i] });
        }

        sort(arr.begin(), arr.end(), greater<vector<int>>());

        int m = arr.size();
        vector<vector<int>> dp(m, vector<int>(m + 1, -1));

        return solve(0, -1, arr, dp);
    }
};