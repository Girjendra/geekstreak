/*
Given an array arr[] of n integers and a 2D array queries[][] representing q queries, where each queries[i] consists of three integers: l, r, and x. For each query determine how many times the element x appears in the arr[] from index l to r (both inclusive).

Return a list of integers where the i-th value represents the answer to the i-th query.
*/
#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        map<int, vector<int>> indexMap;
        vector<int> result;
        for (int i = 0; i < arr.size(); ++i)
            indexMap[arr[i]].push_back(i);
    
        for (auto& q : queries) {
            int l = q[0], r = q[1], x = q[2];
    
            if (indexMap.find(x) == indexMap.end()) {
                result.push_back(0);
                continue;
            }
            vector<int>& ind = indexMap[x];
    
            auto left = lower_bound(ind.begin(), ind.end(), l);
            auto right = upper_bound(ind.begin(), ind.end(), r);
    
            result.push_back(right - left);
        }
    
        return result;
    }
};