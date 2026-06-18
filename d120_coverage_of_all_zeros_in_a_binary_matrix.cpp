/*
Given a binary matrix mat[][] containing only 0s and 1s, find the total coverage of all 0's. The coverage of a particular 0 cell is defined by checking 1's in its four directions (left, right, up, and down). For each direction, if there is at least one 1 anywhere between the 0 and the boundary of the matrix, the coverage increases by one.

Return the sum of the coverage values for all 0 cells in the matrix.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(mat[i][j] == 1)
                    continue;
                
                int row, col;
    
                row = i, col = j;
                while(row >= 0) {
                    if(mat[row][col] == 1) {
                        ans++;
                        break;
                    }
                    row--;
                }
                    
                row = i, col = j;
                while(col < m) {
                    if(mat[row][col] == 1) {
                        ans++;
                        break;
                    }
                    col++;   
                }
                    
                row = i, col = j;
                while(row < n) {
                    if(mat[row][col] == 1) {
                        ans++;
                        break;
                    }
                    row++;
                }
                    
                row = i, col = j;
                while(col >= 0) {
                    if(mat[row][col] == 1) {
                        ans++;
                        break;
                    }
                    col--;
                }
            }
        }
        
        return ans;
    }
};
