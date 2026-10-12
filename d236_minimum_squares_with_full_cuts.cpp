/*
Given a rectangular paper with dimensions n × m, find the minimum number of squares that can be formed by
cutting the paper. Each cut must be made completely across the remaining paper, either horizontally or vertically.

Examples:
Input: n = 4, m = 5
Output: 5
Explanation: One square of size 4 x 4 and four squares of size 1 x 1 are required.

Input: n = 2, m = 4
Output:  2
Explanation: Two squares of size 2 x 2 are enough to fill the rectangle.

Input: n = 11, m = 13
Output: 8
Explanation: One square of size 11 x 11, five squares of size 2 x 2, and two squares of size 1 x 1 are formed by following the rule. Please note that if we are allowed to make partial horizontal or vertical cuts, we can have 6 squares which is a different interesting problem, Min Cut Square.

Constraints:
1 ≤ n, m ≤ 109
*/
#include<iostream>
using namespace std;







// TC : O(max(n, m)) SC: O(1)
class Solution {
public:
    int minSquares(int n, int m) {
        int ans = 0;
        
        while(n > 0 && m > 0) {
            if(n < m)
                swap(n, m);
            
            n -= m;
            ans++;
        }
        
        return ans;
    }
};










// TC : O(log(max(n, m))) SC: O(1)
class Solution {
public:
    int minSquares(int n, int m) {
        int ans = 0;
        
        while(n > 0 && m > 0) {
            if(n < m)
                swap(n, m);
            
            ans += n / m;
            n = n % m;
        }
        
        return ans;
    }
};