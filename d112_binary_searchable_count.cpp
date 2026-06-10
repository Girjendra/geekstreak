/*
Given an array arr[] consisting of n distinct integers, find the maximum count of integers that are binary searchable in the given array. Binary searchable elements are determined using the standard Binary Search implementation described below.

Initially l is 0 and r is size of array - 1 
while(l <= r), compute mid as floor of (l + r)/2 and compare with mid.
If the target element is same as mid, return true. Else if mid is smaller, change l = mid + 1, else change r = mid - 1.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int binarySearch(const vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
    
            if (arr[mid] == target) {
                return mid;
            }
    
            if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    
        return -1;
    }

    int binarySearchable(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        
        for(int it : arr) {
            if(binarySearch(arr, it) != -1)
                ans++;
        }
        
        
        return ans;
    }
};