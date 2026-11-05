/*
Given a string s of length n containing only lowercase English letters, and a permutation array p[] of length n
containing integers from 0 to n - 1.

On the (i + 1)th day, the character at index p[i] in the string is replaced with '?'. For example:

On day 1, replace s[p[0]] with '?'.
On day 2, replace s[p[1]] with '?'.
On day 3, replace s[p[2]] with '?'.
And so on.
Find the minimum number of days required so that no two adjacent characters in s are equal, unless at least one of 
hem is '?'.
Formally, for every index i (0 <= i < n - 1), the string must satisfy: If s[i] != '?' and s[i+1] != '?', then
s[i] != s[i+1].

Examples:
Input: s = "aabb", p = [2, 1, 3, 0]
Output: 2
Explanation:
On Day 1, we replace s[p[0]] (index 2) with '?'. String becomes "aa?b". Index 0 and 1 still have equal adjacent characters 'a'.
On Day 2, we replace s[p[1]] (index 1) with '?'. String becomes "a??b". Now no two adjacent non-'?' characters are equal.

Input: s = "abca", p = [3, 0, 2, 1]
Output: 0
Explanation:
The initial string "abca" already satisfies the condition without replacing any characters.

Constraints:
1 ≤ s.size() ≤ 10^5
0 ≤ p[i] < s.size()
s consists only of lowercase English alphabets
p.size() = s.size()
*/
#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;







// TC : O(n^2), SC: O(1)
class Solution {
public:
    bool isOkay(string& s) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i - 1] == s[i] && s[i] != '?')
                return false;
        }
        
        return true;
    }
    
    int getMinimumDays(string &s, vector<int> &p) {
        int day = 1;
        while(true) {
            if(isOkay(s) || day == p.size())
                break;
            
            s[p[day - 1]] = '?';       
            day++;
        }
        
        return day - 1;
    }
};








// TC : O(n), SC: O(n)
class Solution {
public:
    int getMinimumDays(string &s, vector<int> &p) {
        int n = s.size();
        
        unordered_set<int> st;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1])
                st.insert(i);
        }
        
        if(st.empty())
            return 0;
            
        for(int day = 0; day < n; day++) {
            int ind = p[day];
            
            if(ind - 1 >= 0)
                st.erase(ind - 1);
            
            if(ind < n)
                st.erase(ind);
            
            if(st.empty())
                return day + 1;
        }

        return n;
    }
};