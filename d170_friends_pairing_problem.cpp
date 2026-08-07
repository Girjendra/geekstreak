/*
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
*/
#include<iostream>
#include <vector>
using namespace std;

// TC : O(2^n) SC: O(n)
class Solution {
  public:
    int solve(int n) {
        if(n == 0 || n == 1)
                return 1;

        return solve(n-1) + (n-1)*solve(n-2);
    }
    
    int countFriendsPairings(int n) {
        return solve(n);    
    }
};



// TC : O(n) SC: O(n)
class Solution {
  public:
    int solve(int n, vector<int>& dp) {
        if(n == 0 || n == 1)
                return 1;

        if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = solve(n-1, dp) + (n-1)*solve(n-2, dp);
    }
    
    int countFriendsPairings(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);    
    }
};
