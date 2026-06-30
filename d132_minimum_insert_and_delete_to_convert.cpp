/*
Given two arrays a[] and b[] of size n and m respectively, find the minimum number of insertions and deletions on the array a[], required to make both the arrays identical.

Note: Array b[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at the end.
*/
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        unordered_map<int, int> mp;
    
        for (int i = 0; i < m; i++)
            mp[b[i]] = i;
    
        vector<int> v;
        for (int x : a)
            if (mp.count(x))
                v.push_back(mp[x]);
    
        vector<int> lis;
    
        for (int x : v) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }
    
        int len = lis.size();
        int res = (n - len) + (m - len);
    
        return res;
    }
};