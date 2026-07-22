/*
Given an array arr[], find the minimum number of elements to delete so that the remaining elements form a strictly increasing sequence in the same order.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        int n = arr.size();
        vector<int> tails;
    
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = tails.size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (tails[mid] < arr[i])
                    lo = mid + 1;
                else
                    hi = mid;
            }
    
            if (lo == tails.size())
                tails.push_back(arr[i]);
    
            else
                tails[lo] = arr[i];
        }
    
        return n - tails.size();
    }
};