/*
Given a square matrix mat[][] of size n × n, where each cell contains either 'X' or 'O'. Find the size of the largest square submatrix whose boundary is completely surrounded by 'X'. The cells inside the submatrix can contain either 'X' or 'O'. Only the four sides of the submatrix must contain 'X'.

Return side length of the largest such square submatrix.


Note: A square of size 1 is valid if its only cell is 'X'. If no such square submatrix exists, return 0.
*/
#include<iostream>
#include <vector>
using namespace std;




class Solution {
public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(mat[i][j] == 'X') {
                    right[i][j] = 1;
                    down[i][j] = 1;

                    if(j + 1 < n)
                        right[i][j] += right[i][j + 1];

                    if(i + 1 < n)
                        down[i][j] += down[i + 1][j];
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int len = 1; i + len - 1 < n && j + len - 1 < n;len++) {
                    int bottom = i + len - 1;
                    int rightCol = j + len - 1;

                    if(right[i][j] >= len && right[bottom][j] >= len &&
                        down[i][j] >= len && down[i][rightCol] >= len)
                        ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};