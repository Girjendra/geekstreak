/*
Consider an input where all marks obtained are divided into intervals of consecutive numbers represented as l[] and r[] where l[i] and r[i] represent the starting and ending marks (inclusive) of the i-th interval. 

The intervals are sorted in increasing order and do not overlap.
The rank of a mark is defined by its position among all valid marks in increasing order, with the smallest mark assigned rank 1, the next smallest rank 2, and so on.
Given an array rank[]. for each value in rank[], find the corresponding mark and return as an array.
*/
#include<iostream>
#include <vector>
using namespace std;


// TC : O(n + m) where n is the total number of marks and m is the size of rank array
class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        vector<int> marks;
        
        for(int i = 0; i < l.size(); i++) {
            for(int j = l[i]; j <= r[i]; j++) {
                marks.push_back(j);
            }
        }

        vector<int> ans;

        for(int x : rank)
            ans.push_back(marks[x - 1]);

        return ans;
    }
};