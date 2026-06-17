/*
Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is maximized. At least one cut is mandatory.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int solve(int n) {
         if (n == 0 || n == 1)
            return 0;
        
        vector<int> dp(n + 1, 0);
    

        for (int len = 2; len <= n; len++) {
            int maxValue = 0;

            for (int i = 1; i < len; i++) {
                int directProduct = i * (len - i);
    
                int recursiveProduct = i * dp[len - i];
    
                
                maxValue = max(maxValue, max(directProduct, recursiveProduct));
            }
            dp[len] = maxValue;
        }
    
        return dp[n];
    }
    
    int maxProduct(int n) {
        int ans = solve(n);
        
        return ans;
    }
};