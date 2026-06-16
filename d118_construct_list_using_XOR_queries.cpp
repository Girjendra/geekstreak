/*
There is an array that initially contains only a single value, 0. 

Given a list of queries queries[][] of size q, where each query is of one of the following types:

0 x: Insert x into the array.
1 x: Replace every element a in the array with a ^ x, where ^ denotes the bitwise XOR operator.
Return the array in sorted order after performing all the queries.
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &q) {

        map<int,int> m;
        m[0] = 1;

        int xr = 0;

        for(auto &it : q) {

            if(it[0] == 0) {
                m[it[1] ^ xr]++;
            }
            else {
                xr ^= it[1];
            }
        }

        vector<int> ans;

        for(auto p : m) {

            int val = p.first ^ xr;

            for(int i = 0; i < p.second; i++)
                ans.push_back(val);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};