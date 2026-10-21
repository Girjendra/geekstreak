/*
Given an array arr[], find the minimum sum of a subarray containing atleast one element in the given array.

Examples:
Input: arr[] = [3, -4, 2, -3, -1, 7, -5]
Output: -6
Explanation: The subarray [-4, 2, -3, -1] has the minimum sum, which is -6.

Input: arr[] = [4, -6, 3, -2, 5, -8, 2]
Output: -8
Explanation: The subarray [-8] has the minimum sum, which is -8.

Input: arr[] = [2, 6, 8, 1, 4]
Output: 1
Explanation: The subarray [1] has the minimum sum, which is 1.

Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;







// TC : O(n), SC: O(1)
class Solution {
public:
    int minSubarraySum(vector<int> &arr) {
        int n = arr.size();
            
        int ans = -1e5;
        int cur = -1e5;
        for(int i = 0; i < n; i++) {
            cur = max(-arr[i], cur - arr[i]);
            ans = max(ans, cur);
        }
        
        return -ans;
    }
};









// TC : O(n), SC: O(1)
class Solution {
public:
    int minSubarraySum(vector<int> &arr) {
        int n = arr.size();
            
        int ans = INT_MAX;
        int cur = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(cur > 0)
                cur = arr[i];
            else
                cur += arr[i];
                
            ans = min(ans, cur);
        }
        
        return ans;
    }
};