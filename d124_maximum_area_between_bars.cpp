/*
Given an integer array height[], where height[i] represents the height of the ith bar arranged in a row, find the maximum rectangular area that can be formed by selecting any two bars. The area is calculated based on the original positions of the selected bars.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        vector<pair<int, int>> pairs;
    
        for (int i = 0; i < n; i++)
            pairs.push_back({height[i], i});
        
        sort(pairs.begin(), pairs.end());
    
        int res = 0;
        int minIndSoFar = pairs[n - 1].second;
        int maxIndSoFar = pairs[n - 1].second;
    
        for (int i = n - 2; i >= 0; i--) {
            int idx = pairs[i].second;
            int h = pairs[i].first;
    
            int area1 = h * max(0, abs(idx - minIndSoFar) - 1);
            int area2 = h * max(0, abs(idx - maxIndSoFar) - 1);
    
            res = max({res, area1, area2});
    
            minIndSoFar = min(minIndSoFar, idx);
            maxIndSoFar = max(maxIndSoFar, idx);
        }
    
        return res;
    }
};