/*
Given an array arr[] and an integer k, find the maximum sum among all contiguous subarrays having a length greater than or equal to k.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;


// TC: O(n^2) | SC: O(n)
class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> sum(n+1, 0);
        for(int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + arr[i];
        
        
        int ans = INT_MIN;
        for(int i = 0; i <= n - k; i++)
            for(int j = i + k; j <= n; j++)
                ans = max(ans, sum[j] - sum[i]);
        
        return ans;
    }
};



class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> maxSum(n);
        maxSum[0] = arr[0];
        
        int currMax = arr[0];
        for (int i = 1; i < n; i++) {
            currMax = max(arr[i], currMax + arr[i]);
            maxSum[i] = currMax;
        }
        
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += arr[i];
        
        int res = sum;
        for (int i = k; i < n; i++) {
            sum = sum + arr[i] - arr[i-k];
            
            res = max(res, sum);
            res = max(res, sum + maxSum[i-k]);
        }
        
        return res;
    }
};