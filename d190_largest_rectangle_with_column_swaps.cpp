/*
Given a binary matrix mat[][] of size n × m containing only 0s and 1s, any pair of columns may be swapped any number of times. Return the maximum area of a rectangle consisting entirely of 1's that can be formed after performing the column swaps.
*/
#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
using namespace std;


// TC : O(n*m*log(m)) SC: O(n*m)
class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
    
        vector<vector<int>> height(n, vector<int>(m, 0));
    
        for (int j = 0; j < m; j++) {
            height[0][j] = mat[0][j];
    
            for (int i = 1; i < n; i++)
                if (mat[i][j] == 1)
                    height[i][j] = height[i - 1][j] + 1;
        }
    
        int ans = 0;
    
        for (int i = 0; i < n; i++) {
            vector<int> row = height[i];
            sort(row.rbegin(), row.rend());
            for (int j = 0; j < m; j++)
                ans = max(ans, row[j] * (j + 1));
        }
    
        return ans;
    }
};