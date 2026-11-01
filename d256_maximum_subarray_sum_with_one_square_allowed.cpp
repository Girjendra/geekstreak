/*
Given an integer array arr[], find the maximum subarray sum by squaring at most one element.

Examples:
Input: arr[] =  [-1, -2, 3, -2, 3]
Output: 10
Explanation: The subarray {3, -2, 3} with squaring -2 will give the maximum sum as 3 + 4 + 3 = 10.

Input: arr[] =  [-4, -4, -2, 5, 2, -1]
Output: 27
Explanation: The subarray {5, 2} with squaring 5 will give a maximum sum of 25 + 2 = 27.

Constraints:
1 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;







// TC : O(n^4), SC : O(1)
class Solution {
public:
    int maximumSubarray(vector<int>& arr) {
        int n = arr.size();
        int res = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = i; k <= j; k++) {
                    int sum = 0;
                    for (int x = i; x <= j; x++) {
                        if (x == k)
                            sum += arr[x] * arr[x];
                        else
                            sum += arr[x];
                    }
                    
                    res = max(res, sum);
                }
            }
        }
    
        return res;
    }
};









// TC : O(n), SC : O(n)
class Solution {
public:
    long long maximumSubarray(vector<int>& arr) {
        int n = arr.size();

        vector<long long> left(n + 1, 0);
        vector<long long> right(n + 2, 0);

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            sum = max(0LL, sum);
            left[i + 1] = sum;
        }

        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            sum = max(0LL, sum);
            right[i + 1] = sum;
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long curr = 1LL * arr[i] * arr[i] + left[i] + right[i + 2];
            res = max(res, curr);
        }

        return res;
    }
};