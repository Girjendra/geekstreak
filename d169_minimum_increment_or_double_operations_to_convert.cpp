/*
Given an array arr[]. Initially, you have another array containing only 0s.
In one operation, you may either:

Choose any one element and increase its value by 1, or
Double the values of all elements in the array simultaneously.
Find the minimum number of operations required to transform the initial all-zero array into the given array arr[].
*/
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// TC : O(nlogm) where n is the size of the array and m is the maximum element in the array
using namespace std;
class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int n = arr.size();
        
        int incre = 0;
        int doub = 0;
        for(int i = 0; i < n; i++) {
            int temp = arr[i];
            
            while(temp) {
                int bit = temp & 1;
                incre += bit;
                temp =  temp >> 1;
            }
            
            doub = max(doub, (int)log2(arr[i]));
        }
        
        return incre + doub;
    }
};