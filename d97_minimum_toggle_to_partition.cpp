/*
Given an array arr[] containing only 0 and 1. Find the minimum toggles (switch from 0 to 1 or vice-versa)
required such the array become partitioned, i.e., it has first 0s then 1s.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int oc = 0;
        int ans = 0;
    
        for (int x : arr) {
            if (x == 1)
                oc++;
            else
                ans = min(ans + 1, oc);
        }
    
        return ans;
    }
};