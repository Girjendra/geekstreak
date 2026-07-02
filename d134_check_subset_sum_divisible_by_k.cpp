/*
Given an array arr[] of positive integers and a value k. Return true if the sum of any non-empty subset of the given array is divisible by k otherwise, return false.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        int n = arr.size();

        if (n > k)
            return true;
    
        vector<bool> dp(k, false);
        for (int i = 0; i < n; i++) {
            if (dp[0])
                return true;
    
            vector<bool> temp(k, false);
    
            for (int j = 0; j < k; j++)
                if (dp[j] && !dp[(j + arr[i]) % k])
                    temp[(j + arr[i]) % k] = true;
    
            for (int j = 0; j < k; j++)
                if (temp[j])
                    dp[j] = true;
                    
            dp[arr[i] % k] = true;
        }
    
        return dp[0];
    }
};