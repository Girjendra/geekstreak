/*
Given two integers x and y representing the GCD and LCM of two unknown positive integers a and b, count the number of valid pairs (a, b) satisfying these conditions. Note that (a, b) and (b, a) are counted as distinct pairs when a ≠ b.
*/
#include<iostream>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

// TC : O(y/x*log(min(x, y))) SC: O(1)
class Solution {
  public:
    int pairCount(int x, int y) {
        if(x > y || (y % x))
            return 0;
            
        int st = x;
        
        int ans = 0;
        while(st <= y) {
            int a = st;
            int b = (x * y) / st;
            
            int GCD = gcd(a, b);
            if( GCD == x && (a * b) / GCD == y)
                ans++;
                
            st += x;
        }
        
        return ans;
    }
};