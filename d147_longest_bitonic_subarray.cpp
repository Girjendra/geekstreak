/*
Given an array arr[] containing positive integers, return the maximum length of the bitonic subarray.

A subarray arr[i...j] is considered bitonic if its elements first monotonically increase, and then monotonically decrease. Formally, there exists an index k (where i <= k <= j) such that:

arr[i] <= arr[i+1] <= . . . <= arr[k] 
arr[k] >= arr[k+1] >= . . . >= arr[j]
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int bitonic(vector<int> &arr) {
        int ans = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int left = 0, k = i;
            while(k > 0) {
                if(arr[k-1] > arr[k])
                    break;
                
                k--;
                left++;
            }
            
            
            int right = 0; k = i;
            while(k < n-1) {
                if(arr[k] < arr[k+1])
                    break;
                    
                k++;
                right++;
            }
            
            ans = max(ans, left+right+1);
        }
        
        return ans;
    }
};