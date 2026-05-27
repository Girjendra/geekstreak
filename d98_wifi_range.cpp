/*
There are n rooms in a straight line in Geekland State University's hostel. You are given a
binary string s of length n, where s[i] = '1' means there is a WiFi router in the i-th room,
and s[i] = '0' means there is no WiFi in that room.

Each WiFi router has a range of x, meaning it can cover up to x rooms to its left and x rooms
to its right.

Given x and s, determine whether all rooms are covered by at least one WiFi router. Return
true if all rooms are covered; otherwise, return false.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    bool wifiRange(string &s, int x) {
        int n = s.length();
        vector<int> left(n, -1e9), right(n, 1e9);
        int last = -1e9;
    
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                last = i;
                
            left[i] = last;
        }
    
        last = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1')
                last = i;
            right[i] = last;
        }

        for (int i = 0; i < n; i++) {
            if (abs(i - left[i]) > x && abs(i - right[i]) > x)
                return false;
        }
    
        return true;
    }
};