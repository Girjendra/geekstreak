/*
Given a number n. Find the minimum number of operations required to reach n starting from 0.

You have two operations available:
Double the number
Add one to the number

Examples:
Input: n = 8
Output: 4
Explanation: 0 + 1 = 1 --> 1 + 1 = 2 --> 2 * 2 = 4 --> 4 * 2 = 8.

Input: n = 7
Output: 5
Explanation: 0 + 1 = 1 --> 1 + 1 = 2 --> 1 + 2 = 3 --> 3 * 2 = 6 --> 6 + 1 = 7.

Constraints:
1 ≤ n ≤ 106
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;






// TC : O(2^n) SC : O(n)
class Solution {
public:
    int minOperation(int n) {
        if(n <= 1)
            return n;
            
        int half = INT_MAX;
        if(n % 2 == 0)
            half = 1 + minOperation(n / 2);
            
        int one = 1 + minOperation(n - 1);
        
        return min(half, one);
    }
};







// TC : O(n) SC : O(n)
class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n <= 1)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
            
        int half = INT_MAX;
        if(n % 2 == 0)
            half = 1 + solve(n / 2, dp);
            
        int one = 1 + solve(n - 1, dp);
        
        return dp[n] = min(half, one);
    }
    
    int minOperation(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};







// TC : O(n) SC : O(1)
class Solution {
public:
    int minOperation(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            dp[i] = min(dp[i], 1 + dp[i - 1]);
            
            if(!(i % 2))
                dp[i] = min(dp[i], 1 + dp[i / 2]);
        }
        
        return dp[n];
    }
};








// TC : O(log n) SC : O(1)
class Solution {
public:
    int minOperation(int n) {
        int cnt = 0;
        while (n != 0) {
            if (!(n % 2))
                n /= 2;
            else
                n--;
    
            cnt++;
        }
        
        return cnt;
    }
};