/*
Given a binary string s consisting of 0s and 1s. Find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in a substring of the string.

Note: In the case of all 1s, the answer will be -1.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    int maxSubstring(string &s) {
        int md = 0;
        int cs = 0;
        
        for(char ch : s) {
            cs += (ch == '0' ? 1 : -1);
            
            if(cs < 0)
                cs = 0;
            
            md = max(md, cs);
        }
        
        return md== 0 ? -1 : md;
    }
};