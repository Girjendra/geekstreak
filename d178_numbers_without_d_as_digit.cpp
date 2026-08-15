/*
Given a number n, count the numbers from 1 to n that don’t contain digit d in their decimal representation.
*/
#include<iostream>
#include <cstring>
using namespace std;

// TC : O(n * log n) SC : O(1)
class Solution {
  public:
    bool containsDigit(int num, int d) {
        if (num == 0)
            return d == 0;

        while (num > 0) {
            if (num % 10 == d)
                return true;
            num /= 10;
        }

        return false;
    }
    
    int countWithout(int n, int d) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (!containsDigit(i, d))
                count++;
        }

        return count;
    }
};

// TC : O(log n) SC : O(log n)
class Solution {
  public:
    int countWithout(int n, int d) {
        if (n <= 0)
            return 0;

        string s = to_string(n);
        int length = s.length();
        
        int dp[2][2];
        
        for (int tight = 0; tight < 2; tight++)
            for (int started = 0; started < 2; started++)
                dp[tight][started] = started;

        for (int pos = length - 1; pos >= 0; pos--) {
            int newDp[2][2] = {0};

            for (int tight = 0; tight < 2; tight++) {
                for (int started = 0; started < 2; started++) {
                    int limit = tight ? (s[pos] - '0') : 9;
                    int total = 0;

                    for (int digit = 0; digit <= limit; digit++) {
                        int willStart = started || (digit != 0);

                        if (willStart && digit == d)
                            continue;

                        int newTight = tight && (digit == limit);
                        total += dp[newTight][willStart];
                    }

                    newDp[tight][started] = total;
                }
            }

            memcpy(dp, newDp, sizeof(dp));
        }

        return dp[1][0];
    }
};