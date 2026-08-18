/*
Geek wants to send a secret message to his friend Keeg. Instead of sending the original message directly, he encrypts it by inserting the character '*'.

Keeg decodes the message as follows:

Traverse the encoded string from left to right and initialize the original string as empty.
Whenever a normal character appears, append it to the current original string.
Whenever '*' is encountered, remove it and append all characters before it to the end of the current original string.
Repeat until no '*' remains.

Given the original string s, find the lexicographically smallest encrypted string that decodes to s.
*/
#include<iostream>
#include <stack>
using namespace std;

// TC : O(n^2), SC: O(n)
class Solution {
  public:
    string compress(string &s) {
        int n = s.size();
        stack<char> st;
        
        for(int i = n-1; i > 0; i--) {
            int len = i + 1;
            
            if(len % 2) {
                st.push(s[i]);
                continue;
            }
            
            int half = len / 2;
            bool same = true;
            
            for(int j = 0; j < half; j++) {
                if(s[j] != s[j + half]) {
                    same = false;
                    break;
                }
            }
            
            if(same) {
                st.push('*');
                i = half;
            }
            else
                st.push(s[i]);
        
        }
        
        string ans = "";
        ans.push_back(s[0]);
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
