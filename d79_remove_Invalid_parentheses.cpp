/*
Given a string s consisting of lowercase letters and parentheses '(' and ')'.
A string is considered valid if:
Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
Parentheses are properly nested.
Remove the minimum number of invalid parentheses from s so that the resulting string becomes valid.
Return all the possible distinct valid strings in lexicographically sorted order.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isvalid(string s) {
        int count = 0;
        
        for(char ch : s) {
            if(ch == '(')
                count++;
            else if(ch == ')') {
                count--;
                
                if(count< 0)
                    return false;
            }
        }
        
        return count == 0;
    }
    
    vector<string> validParenthesis(string &s) {
        unordered_set<string> visited;
        queue<string> q;
        vector<string> res;
        
        q.push(s);
        visited.insert(s);
        
        bool found = false;
        
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            
            if(isvalid(cur)) {
                res.push_back(cur);
                found = true;
            }
            
            if(found)
                continue;
                
            for(int i = 0; i < cur.size(); i++) {
                if(cur[i] != '(' && cur[i] != ')')
                    continue;
                    
                string next = cur.substr(0, i) + cur.substr(i + 1);   
                    
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }    
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};
