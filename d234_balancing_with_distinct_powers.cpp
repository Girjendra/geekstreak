/*
Given a simple weighing scale with two pans, a target weight b, and a set of weights where each weight is a distinct power of a, find if the scale can be balanced such that:

b + (some powers of a) = (some other powers of a)

Note: Exactly one weight is available for each power of a, so each power can be used at most once.

Examples:
Input: a = 4, b = 11
Output: true
Explanation: 11 + 4 + 1 = 16. So, target = 11 can be balanced using powers of 4.

Input: a = 3, b = 5
Output: true
Explanation: 5 + 3 + 1 = 9. So, target = 5 can be balanced using powers of 3.

Constraints:
2 ≤ a ≤ 109
1 ≤ b ≤ 109
*/
#include<iostream>
#include <vector>
using namespace std;






// TC : O(3^log(b)) SC: O(log(b))
class Solution {
public:
    bool solve(int i, vector<int>& powers, int diff) {
        if(i == powers.size())
            return diff == 0;
            
        return solve(i + 1, powers, diff) ||
                solve(i + 1, powers, diff + powers[i]) ||
                solve(i + 1, powers, diff - powers[i]);
    }
    
    bool balancePan(int a, int b) {
        vector<int> powers;
        int val = 1;
        while(val <= a * b) {
            powers.push_back(val);
            val *= a;
        }
        
        return solve(0, powers, b);
    }
};







// TC : O(log(b)) SC: O(1)
class Solution {
public:
    bool balancePan(int a, int b) {
        while (b > 0) {
            int rem = b % a;
            if (rem == 0 || rem == 1)
                b /= a;
            else if (rem == a - 1)
                b = b / a + 1;
            else
                return false;
        }
    
        return true;
    }
};