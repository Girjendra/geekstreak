/*
Given a string s made of two characters of 'x' and 'y'.  The task is to verify whether s is made by concatenating substrings
that follow the pattern xnyn  (equal number of y's follow equal number of x's). 

Examples:
Input: s = "xxyyxy" 
Output: true
Explanation: The string can be split into "xxyy" + "xy". Both substrings contain an equal number of consecutive
'x' and 'y' characters.

Input: s = "xyx"
Output: false
Explanation: The last 'x' cannot form a valid substring because it is not followed by a matching 'y'. 

Constraints:
1 ≤ s.size() ≤ 10^5
s consists only of the characters x and y
*/
#include<iostream>
using namespace std;








// TC : O(n) SC : O(1)
class Solution {
public:
    bool findPattern(string& s) {
        int n = s.size();
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'x')
                count++;
            else
                count--;
                
            if(count < 0)
                return false;
        }
        
        return count == 0;
    }
};