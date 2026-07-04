/*
Given a binary string s consists only of 0s and 1s. Calculate the number of substrings that have more 1s than 0s.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countSubstring(string &s) {
        int n = s.size();
        int ans = 0;
        int zero = n;
        int minus = 0;
        vector<int> mp(2 * n + 1, 0);
    
        int cur = zero;
    
        for (auto i : s) {
            if (i == '0')
                cur--;
            else
                cur++;
    
            if (cur <= zero)
                minus++;
    
            mp[cur]++;
        }
    
        for (int i = 0; i < n; i++) {
            ans += (n - i - minus);
            if (s[i] == '1') {
                mp[zero + 1]--;
                zero++;
                minus += mp[zero];
            }
            else {
                mp[zero - 1]--;
                zero--;
                minus--;
                minus -= mp[zero + 1];
            }
        }
    
        return ans;
    }
};