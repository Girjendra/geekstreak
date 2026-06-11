/*
Given a string s of opening and closing brackets '(' and ')' only, find an equal point in the string. An equal point is a position k (0-based) such that the number of opening brackets before position k is equal to the number of closing brackets from position k to the end of the string. If multiple such points exist, return the first valid position.

The string can be split at any position from 0 to n, where n is the length of the string.
If we split at 0, it means there is an empty string on left.
If we split at n, it means there is an empty string on right.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    int findIndex(string &s) {
    int n = s.size();
    int openCnt = 0, closeCnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == ')')
            closeCnt++;
    }

    for (int i = 0; i <= n; i++) {
        if (openCnt == closeCnt)
            return i;
            
        if (i < n) {
            if (s[i] == '(')
                openCnt++;

            if (s[i] == ')')
                closeCnt--;
        }
    }

    return -1;
    }
};