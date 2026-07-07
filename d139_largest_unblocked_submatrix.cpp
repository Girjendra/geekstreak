/*
Given two integers n and m, and an array arr[][] of size k, where arr[i] = [r, c] represents a blocked cell (1-based indexing) in an n × m grid. Each blocked cell blocks its entire row and column. Find the largest continuous unblocked area in the grid.

Note: No two blocked cells are in the same row or the same column.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        int k = arr.size();
        vector<int> rows;
        vector<int> cols;
    
        for (int i = 0; i < k; i++) {
            rows.push_back(arr[i][0]);
            cols.push_back(arr[i][1]);
        }

        rows.push_back(0);
        rows.push_back(n + 1);
    
        cols.push_back(0);
        cols.push_back(m + 1);
    
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
    
        int maxRowGap = 0;
        int maxColGap = 0;
    
        for (int i = 1; i < rows.size(); i++)
            maxRowGap = max(maxRowGap, rows[i] - rows[i - 1] - 1);

        for (int i = 1; i < cols.size(); i++)
            maxColGap = max(maxColGap, cols[i] - cols[i - 1] - 1);

        return maxRowGap * maxColGap;
    }
};