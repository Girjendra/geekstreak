/*
Given an integer array arr[] and two integers l and r, find the number of subarrays whose sum lies in the range [l, r] (inclusive).

A subarray is a contiguous sequence of elements within the array.
*/
#include<iostream>
#include <vector>
using namespace std;

// TC : O(n^2) and SC: O(1)
class Solution {
  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        int ans = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += arr[j];
                
                if(sum >= l && sum <= r)
                    ans++;
            }
        }
        
        return ans;
    }
};


// TC : O(n) and SC: O(1)
class Solution {
  public:
    int countSub(vector<int>& arr, int x) {
        int n = arr.size();
        int st = 0;
        int end = 0;
        int sum = 0;
        int ans = 0;
        
        while(end < n) {
            sum += arr[end];
            
            while(st <= end && sum > x) {
                sum -= arr[st];
                st++;
            }
            
            ans += (end - st + 1);
            end++;
        }
        
        return ans;
    }
    
    int countSubarray(vector<int>& arr, int l, int r) {
        int rcnt = countSub(arr, r);
        int lcnt = countSub(arr, l - 1);
        
        return rcnt - lcnt;
    }
};