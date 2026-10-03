/*
Given a positive integer n, consider a 4n * 4n matrix filled with integers from 1 to (4n) * (4n) in row-major order (left to right, top to bottom). Form two coils from the matrix:

The first coil starts from the top-left cell (0, 0) and spirals inward.
The second coil starts from the bottom-right cell (4n - 1, 4n - 1) and spirals inward in the opposite direction.
Return these two coils in the same order.

Examples:
Input: n = 1
Output: [[1, 5, 9, 13, 14, 15, 11, 7], [16, 12, 8, 4, 3, 2, 6, 10]] 

Input: n = 2
Output:
[[1, 9, 17, 25, 33, 41, 49, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39, 31, 23, 15, 14, 13, 12, 11, 19, 27, 35, 43, 44, 45, 37, 29], 
[64, 56, 48, 40, 32, 24, 16, 8, 7, 6, 5, 4, 3, 2, 10, 18, 26, 34, 42, 50, 51, 52, 53, 54, 46, 38, 30, 22, 21, 20, 28, 36]]  


Constraints:
1 ≤ n ≤ 20
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;





// TC = O(n^2) and SC = O(n^2)
class Solution {
public:
    vector<vector<int>> formCoils(int n) {
        vector<vector<int>> mat(4 * n, vector<int>(4 * n, 0));
        int count = 1;
        for(int i = 0; i < 4 * n; i++)
            for(int j = 0; j < 4 * n; j++)
                mat[i][j] = count++;

        vector<vector<int>> ans;
        int startrow = 0;
        int startcol = 0;
        int endrow = 4 * n - 1;
        int endcol = 4 * n - 1;
        
        vector<int> firstCoil;
        vector<int> secondCoil;
        
        int firstrow = 0;
        int firstcol = 0;
        int secrow = 4 * n - 1;
        int seccol = 4 * n - 1;
        
        while(true) {
            if(startrow > endrow || startcol > endcol)
                break;
            
            // down1
            int temprow = firstrow;
            while(temprow <= endrow)
                firstCoil.push_back(mat[temprow++][firstcol]);
            
            startcol++;
            firstrow = endrow;
            firstcol++;
            
            // up2
            temprow = secrow;
            while(temprow >= startrow)
                secondCoil.push_back(mat[temprow--][seccol]);
                
            endcol--;
            secrow = startrow;
            seccol--;
            
            // left1
            int tempcol = firstcol;
            while(tempcol <= endcol)
                firstCoil.push_back(mat[firstrow][tempcol++]);
                
            endrow--;
            firstcol = endcol;
            firstrow--;
            
            // right2
            tempcol = seccol;
            while(tempcol >= startcol)
                secondCoil.push_back(mat[secrow][tempcol--]);
                
            startrow++;
            seccol = startcol;
            secrow++;
            
            // up1
            temprow = firstrow;
            while(temprow >= startrow)
                firstCoil.push_back(mat[temprow--][firstcol]);
            
            endcol--;
            firstrow = startrow;
            firstcol--;
            
            // down2
            temprow = secrow;
            while(temprow <=  endrow)
                secondCoil.push_back(mat[temprow++][seccol]);
                
            startcol++;
            secrow = endrow;
            seccol++;
            
            // right1
            tempcol = firstcol;
            while(tempcol >= startcol)
                firstCoil.push_back(mat[firstrow][tempcol--]);
                
            startrow++;
            firstcol = startcol;
            firstrow++;
            
            // left2
            tempcol = seccol;
            while(tempcol <= endcol)
                secondCoil.push_back(mat[secrow][tempcol++]);
                
            endrow--;
            seccol = endcol;
            secrow--;
        }
        
        ans.push_back(firstCoil);
        ans.push_back(secondCoil);
        
        return ans;
    }
};






// TC = O(n^2) and SC = O(n^2)
class Solution {
public:
    vector<vector<int>> formCoils(int n) {
        int m = 8 * n * n;
        vector<int> coil1(m), coil2(m);

        coil1[0] = 8 * n * n + 2 * n;
        int curr = coil1[0];

        int flag = 1, step = 2;
        int index = 1;

        while (index < m) {
            for (int i = 0; i < step && index < m; i++)
                curr = coil1[index++] = curr - 4 * n * flag;

            for (int i = 0; i < step && index < m; i++)
                curr = coil1[index++] = curr + flag;

            flag *= -1;
            step += 2;
        }

        for (int i = 0; i < m; i++)
            coil2[i] = 16 * n * n + 1 - coil1[i];

        reverse(coil1.begin(), coil1.end());
        reverse(coil2.begin(), coil2.end());

        return {coil2, coil1};
    }
};