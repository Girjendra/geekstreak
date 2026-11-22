/*
Given an array arr[] and a positive integer k, find the length of the longest subarray whose sum is divisible by k.
Note: If there is no subarray with sum divisible by k, then return 0.

Examples:
Input: arr[] = [2, 7, 6, 1, 4, 5], k = 3
Output: 4
Explanation: The subarray [7, 6, 1, 4] has sum = 18, which is divisible by 3.

Input: arr[] = [-2, 2, -5, 12, -11, -1, 7], k = 3
Output: 5
Explanation: The subarray [2, -5, 12, -11, -1] has sum = -3, which is divisible by 3.

Input: arr[] = [1, 2, -2], k = 2
Output: 2
Explanation: The subarray is [2, -2] has sum = 0, which is divisible by 2.

Constraints:
1 ≤ arr.size(), k ≤ 10^5
-105 ≤ arr[i] ≤ 10^5
*/
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;









// TC : O(n^2) SC : O(1)
class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int sum = 0;
            for (int j = i; j < arr.size(); j++) {
                sum = (sum + arr[j]) % k;
                if (sum == 0)
                    res = max(res, j - i + 1);
            }
        }
        
        return res;
    }
};










// TC : O(n) SC : O(min(n, k))
class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        int n = arr.size(), res = 0;
        unordered_map<int, int> prefIdx;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum = ((sum + arr[i]) % k + k) % k;
            if (sum == 0)
                res = i + 1;
            else if (prefIdx.find(sum) != prefIdx.end())
                res = max(res, i - prefIdx[sum]);
            else
                prefIdx[sum] = i;
        }
        
        return res;
    }
};