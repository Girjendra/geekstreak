/*
Given an array arr[], find and return the maximum product possible with the subset of elements
present in the array.

Note:
The maximum product can be of a single element also.
Since the product can be large, return it modulo 109 + 7.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return arr[0];
        
        long long ans = 1;
        int mod = 1e9 + 7;
        
        int zc = 0, nc = 0;
        int mn = INT_MIN, in = -1;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                zc++;
            else if (arr[i] < 0) {
                nc++;
                if (in == -1 || arr[i] > mn) {
                    mn = arr[i];
                    in = i;
                }
            }
        }
        
        if (zc == n) return 0;
        if (nc == 1 && zc == n - 1) return 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
    
            if (nc % 2 == 1 && i == in) continue;
            ans = (ans * arr[i]) % mod; 
        }

        return ans;
    }
};
