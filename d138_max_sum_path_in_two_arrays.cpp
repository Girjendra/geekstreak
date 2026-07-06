/*
Given two sorted arrays of distinct integers in increasing order a[] and b[], which may have some common elements, find the maximum sum of a path from the beginning of any array to the end of any array. You may switch from one array to the other only at common elements.

Note:  When switching, count the common element only once.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int i = 0, j = 0;
        int m = arr1.size(), n = arr2.size();
        long long result = 0, sum1 = 0, sum2 = 0;
    
        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                sum1 += arr1[i++];
            }
            else if (arr1[i] > arr2[j]) {
                sum2 += arr2[j++];
            }
            else {
                result += max(sum1, sum2) + arr1[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
    
        while (i < m) sum1 += arr1[i++];
        while (j < n) sum2 += arr2[j++];
    
        result += max(sum1, sum2);
    
        return (int)result;
    }
};