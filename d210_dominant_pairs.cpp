/*
Given an even-sized integer array arr[], count the number of dominant pairs. A pair of indices (i, j) is called dominant if all of the following conditions hold:

0 ≤ i < arr.size() / 2
arr.size() / 2 ≤ j < arr.size() 
arr[i] ≥ 5 × arr[j] 
Return the total number of dominant pairs.

Note: 0-based indexing is used.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


// TC : O(n^2) SC: O(1)
class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n / 2; i++) {
            for (int j = n / 2; j < n; j++) {
                if (arr[i] >= 5 * arr[j])
                    count++;
            }
        }

        return count;
    }
};



// TC : O(nlogn) SC: O(1)
class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
    
        sort(arr.begin(), arr.begin() + n / 2);
        sort(arr.begin() + n / 2, arr.end());
    
        int count = 0;
        int right = n / 2;
    
        for (int left = 0; left < n / 2; left++) {
            while (right < n && arr[left] >= 5 * arr[right])
                right++;
    
            count += (right - n / 2);
        }
    
        return count;
    }
};