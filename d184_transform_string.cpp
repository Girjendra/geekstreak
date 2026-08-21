/*

*/
#include<iostream>
#include <map>
using namespace std;

// TC : O(n) + O(n) + O(n) = O(n) SC : O(n) + O(n) = O(n)
class Solution {
  public:
    int transform(string &s1, string &s2) {
        if(s1 == s2)
            return 0;
            
        if(s1.size() != s2.size())
            return -1;
            
        int n = s1.size();
        map<char, int> m;
        for(int i = 0; i < n; i++)
            m[s1[i]]++;
        
        for(int i = 0; i < n; i++) {
            m[s2[i]]--;
            if(!m[s2[i]])
                m.erase(s2[i]);
        }
            
        if(!m.empty())
            return -1;
            
        int i = n-1;
        int j = n-1;
        int ans = 0;
        
        while(i >= 0 && j >= 0) {
            while(i >= 0 && s1[i] != s2[j]) {
                ans++;
                i--;
            }
            
            i--;
            j--;
        }
        
        return ans;
        
    }
};
