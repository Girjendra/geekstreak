/*
Given a matrix mat[][] of size n × m consisting of 0s and 1s. You start at the top-left cell (0, 0) and initially move in the left-to-right direction (i.e., towards the right).

While traversing the matrix, follow these rules:

If the current cell contains 0, continue moving in the same direction.
If the current cell contains 1, change your direction to the right (clockwise turn), and update the cell value to 0.
You continue this process until you move outside the boundaries of the matrix. Your task is to determine the coordinates (row and column index) of the cell from which you exit the matrix.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int i = 0, j = 0, pi = 0, pj = -1, n = mat.size(), m = mat[0].size();
        
        while(i < n && j < m && i >= 0 && j >= 0) {
            int ti = i, tj = j;
            
            if(mat[i][j] == 1) {
                mat[i][j] = 0;
                
                if(pi == i && pj+1 == j)
                    i++;
                else if(pi+1 == i && pj == j)
                    j--;
                else if(pi == i && pj-1 == j)
                    i--;
                else if(pi-1 == i && pj == j)
                    j++;
            }
            else
                if(pi == i && pj+1 == j)
                    j++;
                else if(pi+1 == i && pj == j)
                    i++;
                else if(pi == i && pj-1 == j)
                    j--;
                else if(pi-1 == i && pj == j)
                    i--;
            pi = ti, pj = tj;
        }
        
        return {pi, pj};
    }
};