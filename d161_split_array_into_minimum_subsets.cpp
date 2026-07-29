/*
Given an array arr[] of distinct positive numbers. Split the array into the minimum number of subsets such that each subset contains consecutive numbers.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(arr[i-1]+1 != arr[i])
                ans++;
        }
        
        return ans+1;   
    }
};
