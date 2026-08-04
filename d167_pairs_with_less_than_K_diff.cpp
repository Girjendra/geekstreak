/*
Given an array arr[] of positive integers and an integer k, find the total number of pairs of elements that have an absolute difference strictly less than k.

Note:  Pair (i, j) is considered the same as (j, i).
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


// TC : O(nlogn) + O(n^2) = O(n^2), SC : O(1)
class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        int j = arr.size() - 1;
        int ans = 0;
        
        while(j >= 0) {
            int i = 0;
            while(i < j) {
                if(arr[j] - arr[i] < k) {
                    ans += j - i;
                    break;
                }
                else
                    i++;
            }
            
            j--;
        }
        
        return ans;
    }
}; 

// TC : O(nlogn) + O(n) = O(nlogn), SC : O(1)
class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        int i = 0, n = arr.size();
        int ans = 0;
        
        for(int j = 0; j < n; j++) {
            while(arr[j] - arr[i] >= k)
                i++;
        
            ans += j - i;
        }
        
        return ans;
    }
}; 