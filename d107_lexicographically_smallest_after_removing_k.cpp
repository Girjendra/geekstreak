/*
Given a string s consisting of n lowercase characters. Return the lexicographically smallest string after removing exactly k characters from the string. But you have to correct the value of k, i.e., if the length of the string is a power of 2, reduce k by half, else multiply k by 2. You can remove any k characters.

Note: If it is not possible to remove k (the value of k after correction) characters or if the resulting string is empty return -1.
*/
#include<iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();
        
        if((n & (n-1)) == 0)
            k /= 2;
        else
            k *= 2;
        
        if(k >= n)
            return "-1";
            
        stack<int> st;
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        
        if (k > 0)
            while (k--)
                st.pop();

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
    
        reverse(ans.begin(), ans.end());
        return ans;
    }
};