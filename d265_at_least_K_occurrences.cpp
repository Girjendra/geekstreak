/*
Given an array arr[] and an integer k, find the first element that occurs at least k times in the array.
If multiple elements satisfy the condition, return the element whose k-th occurrence appears earliest in
the array.
If no element occurs at least k times, return -1.
Examples:
Input: arr[] = [1, 7, 4, 3, 4, 8, 7], k = 2
Output: 4
Explanation: Both 7 and 4 occur twice. However, 4 reaches its second occurrence before 7, so the answer
is 4.

Input: arr[] = [3, 1, 3, 4, 5, 1, 3, 3, 5, 4], k = 3
Output: 3
Explanation: The element 3 is the only element that occurs at least 3 times in the array.

Input: arr[] = [10, 8, 2], k = 10
Output: -1
Explanation: No element occurs at least 10 times in the array.

Constraints:
1 ≤ arr.size() ≤ 10^6
0 ≤ arr[i] ≤ 10^6
1 ≤ k ≤ 103
*/
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;






// TC : O(n), SC: O(n)
class Solution {
public:
    int firstElementKTime(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        
            if (mp[arr[i]] == k)
                return arr[i];
        }
        
        return -1;
    }
};