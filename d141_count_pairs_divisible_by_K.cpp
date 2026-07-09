/*
Given an array arr[] and positive integer k, count total number of pairs in the array whose sum is divisible by k.
*/
#include<iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        map<int, int> m;
        for(int it : arr)
            m[(it%k)]++;
            
        int ans = 0;
        
        for(int it : arr) {
            int mode = it % k;
            int diff = (k - mode)%k;
            if(m.find(diff) != m.end()) {
                if(mode == diff) {
                    if(m[diff] != 1)
                        ans += m[diff] - 1;
                }
                else
                    ans += m[diff];
            }
        }
        
        return ans / 2;
    }
};