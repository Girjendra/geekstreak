/*
Given a string s, find the lexicographically smallest string after rotating the string left any number of times including 0.

Example:
Input: s = "abcd"
Output: "abcd"
Explanation: String after each rotation are "abcd", "bcda", "cdab", "dabc" and so on. Lexicographically smallest among them is "abcd".

Input: s = "baca"
Output: "abac"
Explanation: Strings after each rotation are "baca", "acab", "caba", "abac" and so on. Lexicographically smallest among them is "abac".

Constraints:
1 ≤ s.size() ≤ 106
s consists only of lowercase English alphabets
*/
#include<iostream>
#include <algorithm>
using namespace std;




// TC : O(n^2) SC : O(n)
class Solution {
public:
    string lexiString(string &s) {
        string ans = s;
        
        int n = s.size();
        for(int k = 1; k < n; k++) {
            string temp = s;
            
            reverse(temp.begin(), temp.begin() + k);
            reverse(temp.begin() + k, temp.end());
            reverse(temp.begin(), temp.end());
            
            ans = min(ans, temp);
        }
        
        return ans;
    }
};






// TC : O(n^2) SC : O(n)
class Solution {
public:
    string lexiString(string &s) {
        int n = s.size();
        string ans = s;

        for (int i = 1; i < n; i++) {
            string rotation = s.substr(i) + s.substr(0, i);
            if (rotation < ans)
                ans = rotation;
        }

        return ans;
    }
};





// TC : O(n) SC : O(n)
class Solution {
public:
    string lexiString(string &ss) {
        int n = ss.size();
        string s = ss + ss;

        int i = 0, j = 1, k = 0;
        while(i < n && j < n && k < n) {
            char a = s[i + k];
            char b = s[j + k];
            
            if(a == b) {
                k++;
                continue;
            }
            
            if(a > b)
                i = i + k + 1;
            else
                j = j + k + 1;
                
            if(i == j)
                j++;
            
            k = 0;
        }

        return s.substr(min(i, j), n);
    }
};