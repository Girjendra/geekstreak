/*
Given an array arr[]  and a range from l to r, the task is to count the number of triplets having a sum in the range [l, r].
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC : O(n^2) SC: O(1)
class Solution {
  public:
  long long solve(vector<int> &arr, int sum) {
      int n = arr.size();
      long long ans = 0;
      for(int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            if(arr[i] + arr[left] + arr[right] <= sum) {
                ans += right - left;
                left++;
            }
            else
                right--;
        }
    }
    
    return ans;
  }
  
  int countTriplets(vector<int> &arr, int l, int r) {
        sort(arr.begin(), arr.end());
        return solve(arr, r) - solve(arr, l-1);
    }
};