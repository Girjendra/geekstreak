/*
Given an integer x and an array of integers, arr[]. Find the length of the smallest subarray whose sum is strictly
greater than x.
If no such subarray exists, return 0.

Examples:
Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: The smallest subarray with a sum greater than 51 is [4, 45, 6], whose sum is 55 and length is 3.

Input: x = 100, arr[] = [1, 10, 5, 2, 7]
Output: 0
Explanation: No subarray has a sum greater than 100. Hence, the answer is 0.

Constraints:
1 ≤ x, arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^4

*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;







// TC : O(n^2), SC: O(1)
class Solution {
public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = arr.size();
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            int curr = 0;
            
            for (int j = i; j < n; j++) {
                curr += arr[j];
                
                if (curr > x) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
    
        return (res == INT_MAX) ? 0 : res;
    }
};









// TC : O(n), SC: O(1)
class Solution {
public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = arr.size();
        int i = 0, j = 0;
        int ans = INT_MAX, sum = 0;
        
        while(j < n) {
            sum += arr[j++];
                
            while(i < j && sum > x) {
                ans = min(ans, j - i);
                sum -= arr[i++];
            }
        }
        
        return (ans == INT_MAX) ? 0 : ans;
    }
};