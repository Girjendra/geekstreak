/*
Given an integer array arr[] and an integer target, determine whether there exists a pair of elements
in the array whose product is equal to target.
Return true if such a pair exists; otherwise, return false.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        sort(arr.begin(), arr.end());
        
        int i = 0; 
        int j = arr.size()-1;
        
        while(i < j) {
            if(1LL*arr[i]*arr[j] == target)
                return true;
                
            if(1LL*arr[i]*arr[j] > target)
                j--;
            else
                i++;
        }
        
        return false;
    }
};