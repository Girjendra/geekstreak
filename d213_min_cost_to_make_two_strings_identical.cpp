/*
Given two strings s1 and s2, and two integers costS1 and costS2, where costS1 is the cost of deleting one character from s1 and costS2 is the cost of deleting one character from s2, find the minimum cost required to make the two strings identical.

You can delete any number of characters from either string, but the order of the remaining characters must be preserved.


Constraints:
1 ≤ s1.size(), s2.size() ≤ 1000
1 ≤ costS1, costS2 ≤ 105
*/
#include<iostream>
#include <vector>
using namespace std;




// TC : O(n*m) SC : O(n*m)
class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
        
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int LCS = dp[n][m];
        
        int ans = (n - LCS) * costS1 + (m - LCS) * costS2;
        return ans;
    }
};