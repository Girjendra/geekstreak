/*
Given a string s, return the sum of the beauty of all substrings of s. The beauty of a substring is defined as the difference
between the maximum and minimum frequencies of the characters present in that substring.

Examples:
Input: s = "aaac"
Output: 3
Explanation: The substrings with non-zero beauty are "aaac" and "aac". 
For "aaac", the frequencies are a = 3 and c = 1. Its beauty is 3 − 1 = 2. 
For "aac", the frequencies are a = 2 and c = 1. Its beauty is 2 − 1 = 1. 
The remaining substrings have a beauty of 0. Therefore, the sum of the beauties of all substrings is 2 + 1 = 3.

Input: s = "aabc"
Output: 2
Explanation: The substrings with non-zero beauty are "aab" and "aabc". 
For "aab", the frequencies are a = 2 and b = 1. Its beauty is 2 − 1 = 1. 
For "aabc", the frequencies are a = 2, b = 1, and c = 1. Its beauty is 2 − 1 = 1. 
Therefore, the sum of the beauties of all substrings is 1 + 1 = 2.

Constraints:
1 ≤ s.size() ≤ 500
s consists only of lowercase English alphabets
*/
#include<iostream>
#include <climits>
#include <map>
using namespace std;








// TC : O(n^2 * 26 *log 26)
class Solution {
public:
    int beautySum(string &s) {
        int n = s.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            map<char, int> map;
            for(int j = i; j < n; j++) {
                map[s[j]]++;

                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(auto it : map) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                
                ans += (maxi - mini);
            }
        }
        
        return ans;
    }
};








// TC : O(n^2 * 26)
class Solution {
public:
    int beautySum(string &s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int fre[26] = {0};
            for(int j = i; j < n; j++) {
                fre[s[j] - 'a']++;

                int mini = INT_MAX, maxi = INT_MIN;
                for(int k = 0; k < 26; k++) {
                    if(fre[k]) {
                        mini = min(mini, fre[k]);
                        maxi = max(maxi, fre[k]);
                    }
                }
                
                ans += (maxi - mini);
            }
        }
        
        return ans;
    }
};