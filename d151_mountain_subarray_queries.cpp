/*
Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a mountain array. A subarray is called a mountain array if there exists an index k (l ≤ k ≤ r) such that: arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].

Elements of a Mountain subarray are first non-decreasing and then non-increasing.
A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();

        vector<int> dec(n);
        dec[n - 1] = n - 1;
    
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                dec[i] = dec[i + 1];
            else
                dec[i] = i;
        }
    
        vector<int> inc(n);
        inc[0] = 0;
    
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1])
                inc[i] = inc[i - 1];
            else
                inc[i] = i;
        }
    
        vector<bool> ans;
        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];
    
            ans.push_back(dec[l] >= inc[r]);
        }
    
        return ans;
    }
};