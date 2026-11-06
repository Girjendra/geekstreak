/*
Given a height h, find the maximum number of distinct balanced binary trees of height exactly h.
A binary tree is balanced if, for every node, the heights of its left and right subtrees differ by at most 1. A tree with a
single node has height 1. An empty tree has height 0.
Note: Since the answer can be very large, return it modulo 109 + 7.

Examples:
Input: h = 1
Output: 1
Explanation: Only one tree of height 1 exists i.e. a single node.

Input: h = 2
Output: 3 
Explanation: 3 distinct balanced trees of height 2 exist.

Input: h = 3
Output: 15
Explanation: 15 distinct balanced trees of height 3 exist.

Constraints:
1 ≤ h ≤ 10^6
*/
#include<iostream>
#include <vector>
using namespace std;







// TC : O(2^h) SC :O(h)
class Solution {
public:
    long long MOD = 1000000007;
    int countBT(int h) {
        if(h <= 1)
            return 1;
            
        long long a = countBT(h - 1);
        long long b = countBT(h - 2);
        
        return ((a * a) % MOD + (2 * a * b) % MOD) % MOD;
    }
};









// TC : O(n) SC : O(h)
class Solution {
public:
    long long MOD = 1000000007;
    int countBT(int h) {
        vector<long long> dp(h + 1, 0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= h; i++)
            dp[i] = ((dp[i - 1] * dp[i - 1]) % MOD + (2 * dp[i - 1] * dp[i - 2]) % MOD) % MOD;
            
        return dp[h];
    }
};









// TC : O(n) SC : O(1)
class Solution {
public:
    long long MOD = 1000000007;
    int countBT(int h) {
        long long prev2 = 1;
        long long prev1 = 1;
        
        for(int i = 2; i <= h; i++) {
            long long cur = ((prev1 * prev1) % MOD + (2 * prev1 * prev2) % MOD) % MOD;
            
            prev2 = prev1;
            prev1 = cur;
        }
            
        return prev1;
    }
};