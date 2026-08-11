/*
Given a binary matrix mat[][] of size n*m and an integer k, process a list of queries queries[][]. Each query contains coordinates [i, j] of the center of a square.

For every query, find the side length of the largest odd-sized square centered at cell (i, j) such that the square contains at most k ones.
 A square centered at (i, j) expands outward symmetrically in all four directions by the same number of cells, so its side length is always odd.
Note: If no odd-sized square centered at the given cell satisfies the condition of containing at most k ones, return -1 for that query.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat,
                vector<vector<int>>& queries, int k) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                pre[i][j] = mat[i-1][j-1]
                          + pre[i-1][j]
                          + pre[i][j-1]
                          - pre[i-1][j-1];
            }
        }

        auto countOnes = [&](int r1, int c1, int r2, int c2) {
            return pre[r2+1][c2+1]
                 - pre[r1][c2+1]
                 - pre[r2+1][c1]
                 + pre[r1][c1];
        };

        vector<int> ans;

        for(auto q : queries) {
            int r = q[0];
            int c = q[1];

            int best = -1;

            for(int side = 1; ; side += 2) {

                int radius = side / 2;

                int r1 = r - radius;
                int r2 = r + radius;
                int c1 = c - radius;
                int c2 = c + radius;

                if(r1 < 0 || r2 >= n || c1 < 0 || c2 >= m)
                    break;

                int ones = countOnes(r1, c1, r2, c2);

                if(ones <= k)
                    best = side;
                else
                    break;
            }

            ans.push_back(best);
        }

        return ans;
    }
};