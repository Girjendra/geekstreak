/*
Given an array of integers and a number k, the task is the find maximum pair sum with the following conditions on the pairs.

Pair difference should be less than k.
Pairs should be disjoint. For example if (x, y) is a result pair, then neither x nor y should appear in any other result pair.
Sum of p pairs means sum of 2p elements in the result.
If no valid pairs can be formed, return 0.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int maxsum = 0;
        
        for(int i = n-1; i > 0; i--) {
            if(arr[i] - arr[i-1] < k) {
                maxsum += arr[i];
                maxsum += arr[i-1];
                i--;
            }
        }
        
        return maxsum;
    }
};