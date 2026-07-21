/*
Given a string s containing lowercase English alphabets.

Start from any index containing the character 'a' and perform jump operations.
In each jump operation, move to any index on the right side whose character is the immediate next letter of the current character in the alphabet (i.e., 'a' to 'b', 'b' to 'c', 'c' to 'd', and so on). 
Continue performing jumps until no further jump is possible.
Find the maximum possible difference between the starting index and the ending index. If it is not possible to choose a starting index, return -1.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int solve(int i, int n, string& s) {
        int end = i;

        for(int j = i + 1; j < n; j++)
            if(s[j] == (s[i]+1))
                end = max(end, solve(j, n, s));

        return end;
    }
    
    int maxIndexDifference(string &s) {
        int i = 0;
        int n = s.size();
        int ans = -1;
        
        while(i < n) {
            if(s[i] == 'a')
                ans = max(ans, solve(i, n, s)-i);
                
            i++;
        }
        
        return ans;
    }
};



class Solution {
  public:
    int solve(int i, int n, string& s, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];
        
        int end = i;
        
        for(int j = i + 1; j < n; j++)
            if(s[j] == (s[i]+1))
                end = max(end, solve(j, n, s, dp));

        return dp[i] = end;
    }
    
    int maxIndexDifference(string &s) {
        int i = 0;
        int n = s.size();
        int ans = -1;
        vector<int> dp(n, -1);
        
        while(i < n) {
            if(s[i] == 'a')
                ans = max(ans, solve(i, n, s, dp)-i);
                
            i++;
        }
        
        return ans;
    }
};




class Solution {
  public:
    int maxIndexDifference(string &s) {
        int n = s.size();
        vector<int> best(26, -1);
        
        int ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            int farthest = i;
            if (s[i] != 'z' && best[s[i] - 'a' + 1] != -1)
                farthest = best[s[i] - 'a' + 1];

            best[s[i] - 'a'] = max(best[s[i] - 'a'], farthest);
            
            if (s[i] == 'a')
                ans = max(ans, farthest - i);
        }
        
        return ans;
    }
};
