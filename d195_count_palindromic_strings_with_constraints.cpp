/*
Given two integers n  and k, consider an alphabet consisting of the first k lowercase English letters. Find the number of palindromic strings whose length is less than or equal to n, such that:

Every character in the string belongs to the given alphabet.
No character appears more than twice in the string.
Note: Since the answer can be very large, return it modulo 10^9+7.
*/
#include<iostream>
using namespace std;

// TC : O(n*k) SC: O(1)
class Solution {
  public:
    int MODE =  1e9 + 7;
    int solve(int n, int k) {
        int ans = 1;

        int half = (n + 1) / 2;
        
        while(half) {
            ans = (1LL * ans * k) % MODE;
            half--;
            k--;
        }

        return ans;
    }
    
    int palindromicStrings(int n, int k) {
        long long ans = 0;

        for(int i = 1; i <= n; i++)
            ans = (ans + solve(i, k)) % MODE;

        return ans;
    }
};