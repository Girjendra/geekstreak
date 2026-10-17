/*
Given two strings s1 and s2, consisting only of the characters 'A', 'B', and '#'. Determine whether s1 can be transformed into s2 by performing the following operations on s1:
'A' can move only towards the left. 
'B' can move only towards the right.
Neither 'A' nor 'B' can cross each other.
'#' represents an empty position through which 'A' and 'B' can move.
Moving the character at index i one step to the left means swapping it with the character at index i - 1, provided i - 1 >= 0. Similarly, moving it one step to the right means swapping it with the character at index i + 1, provided i + 1 < s1.length().
Return true if s1 can be transformed into s2; otherwise, return false.

Examples:
Input: s1 = #A#B#B#, s2 = A###B#B
Output: true
Explanation: The character 'A' in s1 can move one position towards the left to reach its position in s2, as there are no 'B' characters blocking its movement. Similarly, each 'B' can move towards the right to reach its corresponding position in s2 without crossing any other 'A' or 'B'. Therefore, s1 can be transformed into s2, so the answer is true.

Input: s1 = #A#B#, s2 = #B#A#
Output: false
Explanation: The character 'A' in s1 is at index 1, whereas the corresponding 'A' in s2 is at index 3. Since 'A' can move only towards the left, it cannot reach a position to the right of its current position. Therefore, s1 cannot be transformed into s2, and hence, the answer is false.

Constraints:
1 ≤ s1.size(), s2.size() ≤ 105
*/
#include<iostream>
#include <vector>
using namespace std;







class Solution {
public:
    bool isItPossible(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
    
        if (m!= n) return false;
    
        vector<pair<int, char>> chars1, chars2;
        for (int i = 0; i < m; i++)
            if (s1[i]!= '#') chars1.push_back({i, s1[i]});
        for (int j = 0; j < n; j++)
            if (s2[j]!= '#') chars2.push_back({j, s2[j]});
    
        if (chars1.size()!= chars2.size()) return false;
        
        for (int k = 0; k < (int)chars1.size(); k++) {
            int pos1 = chars1[k].first, pos2 = chars2[k].first;
            char c1 = chars1[k].second, c2 = chars2[k].second;
    
            if (c1!= c2) return false;
            if (c1 == 'A' && pos2 > pos1) return false;
            if (c1 == 'B' && pos2 < pos1) return false;
        }
    
        return true;
    }
};