/*
Given a string s consisting of lowercase English letters, find the maximum number of characters between any two identical characters. If no character repeats, return -1.
*/

#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxCharGap(string &s) {
        vector<pair<int, int>> v(26, pair<int, int>{s.size()+1, -1});
        
        for(int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            v[ch].first = min(v[ch].first, i);
            v[ch].second = max(v[ch].second, i);
        }
        
        int ans = -1;
        for(auto it : v) {
            if(it.second != s.size()+1 && it.first != -1)
                ans = max(ans, it.second - it.first - 1);
        }
        
        return ans;
    }
};