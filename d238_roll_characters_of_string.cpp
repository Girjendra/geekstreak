/*

*/
#include<iostream>
#include <vector>
using namespace std;






// TC : O(n + m) SC : O(n)
class Solution {
public:
    string findRollOut(string& s, vector<int>& roll) {
        int n = s.size();
        vector<int> temp(n, 0);
        
        for(int it : roll) {
            temp[it - 1]++;
            temp[it - 1] %= 26;
        }
        
        for(int i = n - 2; i >= 0; i--){
            temp[i] += temp[i + 1];
            temp[i] %= 26;
        }
        
        for(int i = 0; i < n; i++)
            s[i] = ((s[i] + temp[i] - 'a') % 26) + 'a';
        
        return s;
    }
};