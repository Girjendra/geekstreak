/*
Given a string s and an integer k, check if it is possible to convert s to a string that is repetition of a substring with k characters else returns false. In order to convert we can replace one substring of length k with any k characters.

Note:  In one operation, you can replace any substring of length k whose starting index i (0-based) satisfies i % k == 0 with any sequence of k characters.
*/
#include<iostream>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    bool kSubstr(string &s, int k) {
        int n = s.length();
        if (n%k!= 0)
            return false;
    
        unordered_map<string, int> mp;
        for (int i=0; i<n; i+=k)
            mp[s.substr(i, k)]++;
    
        if (mp.size() == 1)
            return true;

        if (mp.size()!= 2)
            return false;
    
        if ((mp.begin()->second == (n/k - 1)) || mp.begin()->second == 1)
            return true;
    
        return false;
    }
};