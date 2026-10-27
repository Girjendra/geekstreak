/*
Given a string s consisting only of the characters 'A' and 'B', you can toggle any character.
A toggle changes 'A' to 'B' or 'B' to 'A'.

The weight of a string is calculated using the following rules:

An alternating adjacent pair ("AB" or "BA") contributes 4 to the weight.
Each character can belong to at most one pair, so the pairs must not overlap.
Every character that does not belong to any pair contributes 1 to the weight.
Each toggle performed decreases the total weight by 1.
Therefore, Weight = Weight of alternating adjacent pairs + Weight of characters that do not belong
to any pair - Number of Toggles

You can toggle characters to make adjacent characters different and form pairs. Find the maximum
possible weight obtainable from the string by choosing pairs and toggling characters optimally.

Examples:
Input: s = "AA"
Output: 3
Explanation: The possible transformed strings are "AA", "AB", "BA", and "BB". The strings "AB" and "BA"
each contain one alternating adjacent pair, contributing 4 to the weight. One toggle is required to obtain
either string from "AA", reducing the weight by 1. Therefore, the maximum weight is 4 - 1 = 3.

Input: s = "ABB"
Output: 5
Explanation: Possible transformations are "ABB", "ABA", "AAB", "AAA", "BBB", "BBA", "BAB" and "BAA".
The original string "ABB" contains the alternating adjacent pair "AB", contributing 4 to the weight,
while the remaining character 'B' contributes 1. No toggles are required. Therefore, the maximum weight
is 4 + 1 = 5.

Constraints:
1 ≤ s.size() ≤ 105
s consists only of the characters A and B
*/
#include<iostream>
#include <vector>
using namespace std;







// TC : O(2^n) and SC : O(n)
class Solution {
public:
    int solve(int i, string& s) {
        int n = s.size();
        if (i >= n)
            return 0;

        int ans = 1 + solve(i + 1, s);
        if (i + 1 < n) {
            if (s[i] != s[i + 1])
                ans = max(ans, 4 + solve(i + 2, s));
            else
                ans = max(ans, 3 + solve(i + 2, s));
        }

        return ans;
    }

    int getMaxWeight(string &s) {
        return solve(0, s);
    }
};








// TC : O(n) and SC : O(n)
class Solution {
public:
    int solve(int i, string& s, vector<int>& dp) {
        int n = s.size();
        if (i >= n)
            return 0;
    
        if(dp[i] != -1)
            return dp[i];
            
        int ans = 1 + solve(i + 1, s, dp);
        if (i + 1 < n) {
            if (s[i] != s[i + 1])
                ans = max(ans, 4 + solve(i + 2, s, dp));
            else
                ans = max(ans, 3 + solve(i + 2, s, dp));
        }

        return dp[i] = ans;
    }

    int getMaxWeight(string &s) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, dp);
    }
};








// TC : O(n) and SC : O(n)
class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];
            
            if(i + 1 < n) {
                int pairweight = (s[i] != s[i + 1]) ? 4 : 3;
                
                dp[i] = max(dp[i], pairweight + dp[i + 2]);
            }
        }
        
        return dp[0];
    }
};









// TC : O(n) and SC : O(1)
class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.size();
        int next1 = 0;
        int next2 = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            int cur = 1 + next1;
            
            if(i + 1 < n) {
                int pairweight = (s[i] != s[i + 1]) ? 4 : 3;
                cur = max(cur, pairweight + next2);
            }
            
            next2 = next1;
            next1 = cur;
        }
        
        return next1;
    }
};