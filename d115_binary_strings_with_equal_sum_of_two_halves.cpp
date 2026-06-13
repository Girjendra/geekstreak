/*
Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits. 

Note: Since the anwer can be very large, so return the answer modulo 109+7.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    int MOD = 1e9 + 7;
    
    long long power(long long a, long long b) {
        long long ans = 1;
        
        while (b) {
            if (b & 1)
                ans = (ans * a) % MOD;
    
            a = (a * a) % MOD;
            b >>= 1;
        }
    
        return ans;
    }
    
    int computeValue(int n) {
        long long fact1 = 1;
        long long fact2 = 1;
    
        for (int i = 1; i <= 2 * n; i++)
            fact1 = (fact1 * i) % MOD;

        for (int i = 1; i <= n; i++)
            fact2 = (fact2 * i) % MOD;
    
        long long denom = (fact2 * fact2) % MOD;
        long long ans = (fact1 * power(denom, MOD - 2)) % MOD;
    
        return ans;
    }
};