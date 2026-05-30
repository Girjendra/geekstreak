/*
Given an array arr[] of n integers, modify the array in-place such that each element is replaced with
the XOR of its adjacent elements.

For the first element, update arr[0] = arr[0] ^ arr[1].
For the last element, update arr[n-1] = arr[n-2] ^ arr[n-1].
For all other elements, update arr[i] = arr[i-1] ^ arr[i+1].
Note: Here, a ^ b represents the XOR operation between a and b. 
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n = arr.size();
       
        int l = arr[0];
        arr[0] = arr[0] ^ arr[1];
        
        for(int i = 1; i < n-1; i++) {
            int temp = arr[i];
            arr[i] = l ^ arr[i+1];
            l = temp;
        }
        
        arr[n-1] = l ^ arr[n-1];
    }
};