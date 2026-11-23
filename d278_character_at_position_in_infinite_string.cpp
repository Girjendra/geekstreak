/*
Given a string s and an integer pos, an infinite string is constructed by repeatedly applying the following operation. In the i-th step, append i
consecutive $ characters, followed by the reverse of the current string, to the current string.
Formally, if the current string is s, update it as:
s = s + ('$' repeated i times) + reverse(s)
The initial string is the given s, and the process continues indefinitely.

Find and return the character at the pos(1-based indexing) in the resulting infinite string.

Examples:
Input: s = "12345", pos = 3
Output: 3
Explanation: In "12345...", the character at pos 3 is 3.

Input: s = "12345", pos = 10
Output: 2
Explanation: In "12345$54321...", the character at pos 10 is 2.

Input: s = "abc", pos = 7
Output: a
Explanation: In "abc$cba...", the character at pos 7 is a.

Constraints:
1 ≤ s.size() ≤ 10^5
1 ≤ pos ≤ 10^9
s consists of English alphabets and digits
*/
#include<iostream>
#include <algorithm>
using namespace std;










// TC : O(pos) SC : O(pos)
class Solution {
public:
    char posInfinite(string &s, int pos) {
        int i = 1;
        while(pos > s.size()) {
            string rev = s;
            reverse(rev.begin(), rev.end());
            s += string(i, '$') + rev;
            i++;
        }    
        
        return s[pos - 1];
    }
};











// TC : O(log(pos)) SC : O(1)
class Solution {
public:
    char posInfinite(string &s, int pos) {
        int n = s.size(), len = n, step = 1;
        
        while(len < pos)
            len = 2 * len + step++;

        while(step > 1) {
            long long prevlen = (len - (step - 1)) / 2;

            if(pos > prevlen && pos <= (prevlen + step - 1))
                return '$';
            else if(pos <= prevlen)
                len = prevlen;
            else {
                pos = len - pos + 1;
                len = prevlen;
            }
            
            step--;
        }    
        
        return s[pos - 1];
    }
};