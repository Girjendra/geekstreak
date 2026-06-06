/*
Given two integers n and m representing the dimensions of a chessboard, find the number of ways to place one black knight and one white knight on the chessboard such that they cannot attack each other.

Note:

The knights have to be placed on different squares.
A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped).
The knights attack each other if one can reach the other in one move.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    int numOfWays(int n, int m) {
        long long total = (m*n)*(m*n - 1);
        
        long long ans = 0;
        
        int xaxis[]{-2, +2, -1, +1};
        int yaxis[]{+1, +1, +2, +2};
        
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 4; k++) {
                    int X = i + xaxis[k];
                    int Y = j + yaxis[k];
                    
                    if(X >= 0 && X < n && Y >= 0 && Y < m)
                        ans += 2;
                }
            }
        }
        
        return total - ans;
    }
};