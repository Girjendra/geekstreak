/*
Given two integers a and b in the form of strings. Return the last digit of ab.
*/
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        if(b == "0")
            return 1;

        unordered_map<int, vector<int>> mp = {
            {0, {0}},
            {1, {1}},
            {2, {2, 4, 8, 6}},
            {3, {3, 9, 7, 1}},
            {4, {4, 6}},
            {5, {5}},
            {6, {6}},
            {7, {7, 9, 3, 1}},
            {8, {8, 4, 2, 6}},
            {9, {9, 1}}
        };

        int digit = a.back() - '0';
        vector<int>& cycle = mp[digit];
        int len = cycle.size();

        int rem = 0;
        for(char ch : b)
            rem = (rem * 10 + (ch - '0')) % len;
        
        if(rem == 0)
            rem = len;

        return cycle[rem - 1];
    }
};