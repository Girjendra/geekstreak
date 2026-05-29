/*
Given a string s consisting of digits, you can split it into contiguous substrings (sub-groups).
For example, the string "112" can be split as: ["1","1","2"], ["11","2"], ["1","12"], and ["112"].

A grouping is considered valid if the sums of digits of the sub-groups form a non-decreasing sequence
from left to right.

Determine the total number of such valid groupings for the given string.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int solve(string& s, int index, int prevsum, vector<vector<int>>& dp) {
        if(index == s.size())
            return 1;
        if(dp[index][prevsum] != -1)
            return dp[index][prevsum];
        int ans = 0;
        int cs = 0;
        
        for(int i = index; i < s.size(); i++) {
            cs += s[i] - '0';
            
            if(cs >= prevsum)
                ans += solve(s, i+1, cs, dp);
        }
        return dp[index][prevsum] = ans;
    }
    
    int validGroups(string &s) {
        int n = s.length();
        
        vector<vector<int>> dp(n+1, vector<int>(n*9, -1));
        return solve(s, 0, 0, dp);
    }
};