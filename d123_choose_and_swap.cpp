/*
Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.
*/#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    string chooseSwap(string &s) {
        int n = s.size();
        vector<int> first(26, -1);
    
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1)
                first[ch] = i;
        }
    
        char x = 0, y = 0;
        int pos = -1;

        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';
            for (int c = 0; c < cur; c++) {
                if (first[c] > i) {
                    pos = i;
                    x = s[i];
                    y = char('a' + c);
                    break;
                }
            }
    
            if (pos != -1)
                break;
        }
    
        if (pos == -1)
            return s;
    
        string res = s;
        for (char &ch : res) {
            if (ch == x)
                ch = y;
            else if (ch == y)
                ch = x;
        }
    
        return res;
    }
};
