/*
Given a string s consisting of lowercase English letters and the character '?', 
Replace every '?' with a lowercase English letter such that the resulting string is a palindrome.
If it is possible to form a palindrome, return the minimum possible sum of the absolute ASCII
differences between every pair of adjacent characters in the resulting string.
If it is not possible to form a palindrome, return -1.

Examples:
Input: s = a???c??c????
Output: 4
Explanation: One optimal palindrome is "abbbccccbbba". The sum of the absolute ASCII differences between
adjacent characters is 1 + 0 + 0 + 1 + 0 + 0 + 0 + 1 + 0 + 0 + 1 = 4, which is the minimum possible. 

Input: s = a???c??c???c
Output: -1
Explanation: It is not possible to replace the '?' characters to make the string a palindrome because the first
and last characters are different and cannot be changed.

Constraints:
1 ≤ s.size() ≤ 105
*/
#include<iostream>
using namespace std;






// TC : O(n) SC : O(1)
class Solution {
public:
    int minimumSum(string &s) {
        int n = s.size();
        for(int i = 0, j = n - 1; i <= j; i++, j--) {
            if(s[i] != '?' && s[j] == '?')
                s[j] = s[i];
            else if(s[i] == '?' && s[j] != '?')
                s[i] = s[j];
            else if(s[i] != '?' && s[j] != '?' && s[i] != s[j])
                return -1;
        }

        int i = 0;
        int j = n - 1;
        while(i <= j) {
            if(s[i] == '?') {
                if(i == 0) {
                    int temp = i + 1;
                    while(i <= (n + 1) / 2 && s[temp] == '?') temp++;
                    if(temp < (n + 1) / 2)
                        s[i] = s[j] = s[temp];
                    else
                        s[i] = s[j] = 'a';
                }
                else {
                    s[i] = s[j] = s[i - 1]; 
                }
            }

            i++;
            j--;
        }

        int ans = 0;
        for(int i = 1; i < n; i++)
            ans += abs(s[i] - s[i - 1]);

        return ans;
    }
};