/*
Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.

Note: After skipping the element, the subarray must still be non-empty.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
    
        vector<int> pre(n);
        vector<int> suff(n);

        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
            pre[i] = max(arr[i], pre[i - 1] + arr[i]);

        suff[n - 1] = arr[n - 1];
    
        for (int i = n - 2; i >= 0; i--)
            suff[i] = max(arr[i], suff[i + 1] + arr[i]);

        int ans = *max_element(pre.begin(), pre.end());

        for (int i = 1; i < n - 1; i++)
            ans = max(ans, pre[i - 1] + suff[i + 1]);

        return ans;
        
    }
};