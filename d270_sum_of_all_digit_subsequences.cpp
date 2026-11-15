/*
Given a string s which consists of digits, find sum of all digits across all non-empty subsequences of s.

Note: Since the answer can be very large, return it modulo 10^9 + 7.

Examples:
Input: s = "123" 
Output: 24
Explanation: The non-empty subsequences are: [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]. The sum of all
digits in these subsequences is: 1 + 2 + 3 + (1 + 2) + (1 + 3) + (2 + 3) + (1 + 2 + 3) = 24.

Input: s = "405"
Output: 36
Explanation: The non-empty subsequences are: [4], [0], [5], [4, 0], [4, 5], [0, 5], [4, 0, 5]. The sum of all
digits in these subsequences is 36.

Constraints:
1 ≤ s.size() ≤ 10^5
s consists only of digits(1 - 9).
*/
#include<iostream>
#include <vector>
using namespace std;








// TC : O(2^n) and SC: O(n)
class Solution {
public:
    int MODE = 1e9 + 7;
    void solve(string& s, int i, int cs, int& ans) {
        if(i == s.size()) {
            ans = (ans + cs) % MODE;   
            return ;
        }
        
        solve(s, i + 1, cs, ans);
        solve(s, i + 1, cs + (s[i] - '0'), ans);
    }
    
    int subsequenceSum(string &s) {
        int ans = 0;
        solve(s, 0, 0, ans);
        return ans;
    }
};








// TC : O(n) and SC: O(n)
class Solution {
public:
    int MODE = 1e9 + 7;

    int subsequenceSum(string &s) {
        int n = s.size();
        vector<long long> dp(n, 0);
        dp[0] = s[0] - '0';
        long long power = 2;

        for (int i = 1; i < n; i++) {
            int dig = s[i] - '0';
            dp[i] = (2LL * dp[i - 1] + power * dig) % MODE;
            power = (power * 2) % MODE;
        }

        return dp[n - 1];
    }
};









// TC : O(n) and SC: O(1)
class Solution {
public:
    int MODE = 1e9 + 7;
    int subsequenceSum(string &s) {
        int n = s.size();
        long long prev = s[0] - '0';
        long long power = 2;

        for (int i = 1; i < n; i++) {
            int dig = s[i] - '0';
            long long cur = (2LL * prev + power * dig) % MODE;
            power = (power * 2) % MODE;
            prev = cur;
        }

        return prev;
    }
};