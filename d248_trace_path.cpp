/*
Given a rectangular grid with n rows and m columns, and a string s representing a sequence of movement commands. Geek can start from any
cell of the grid and follows all the commands in s in the same order.
The string s consists only of the characters L, R, D, and U, where:
L: Move one cell left, from (i, j) to (i, j - 1).
R: Move one cell right, from (i, j) to (i, j + 1).
D: Move one cell up, from (i, j) to (i - 1, j).
U: Move one cell down, from (i, j) to (i + 1, j).
Determine whether there exists at least one starting cell such that Geek remains within the grid after performing all the commands in s.

Examples:
Input: n = 1, m = 1, s = "R"
Output: false
Explanation: There is only one cell(1, 1). So Geek can only start from (1, 1). On taking right(R) Geek moves to (1, 2), which is out of grid.
Therefore, there is no cell from where Geek can start and remain inside the grid after tracing the route. 

Input: n = 2, m = 3, s = "LLRU"
Output: true
Explanation: One possible cell is (1, 3). (1, 3) -> (1, 2) -> (1, 1) -> (1, 2) -> (2, 2). Thus, there is a cell from where if Geek starts, it
remains inside the grid throughout tracing the route.


Constraints:
1 ≤ n, m, s.size() ≤ 104
s consists only of the characters L R D and U.
*/

#include<iostream>
using namespace std;






// TC : O(n*m*|s|) SC : O(1)
class Solution {
public:
    bool isPossible(int n, int m, string& s) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int row = i;
                int col = j;
                bool possible = true;

                for (char ch : s) {
                    if (ch == 'L')
                        col--;
                    else if (ch == 'R')
                        col++;
                    else if (ch == 'U')
                        row--;
                    else if (ch == 'D')
                        row++;
    
                    if (row < 0 || row >= n || col < 0 || col >= m) {
                        possible = false;
                        break;
                    }
                }
    
                if (possible)
                    return true;
            }
        }
    
        return false;
    
    }
};











// TC : O(|s|) SC : O(1)
class Solution {
public:
    bool isPossible(int n, int m, string& s) {
        int i = 0;
        int j = 0;
        int minI = 0, maxI = 0;
        int minJ = 0, maxJ = 0;
                
        for(int k = 0; k < s.size(); k++) {
            char ch = s[k];
            
            if(ch == 'L') j--;
            else if(ch == 'R') j++;
            else if(ch == 'U') i++;
            else i--;
                
            minI = min(minI, i);
            maxI = max(maxI, i);
            minJ = min(minJ, j);
            maxJ = max(maxJ, j);
        }
        
        return (maxI - minI + 1 <= n) && (maxJ - minJ + 1 <= m);    }
};