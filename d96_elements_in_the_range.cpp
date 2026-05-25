/*
Given an array arr[] containing distinct positive integers, and two integers start and end
defining a range. Determine if the array contains all elements within inclusive range [start, end].
Note: If the array contains all elements in the given range return true otherwise return false.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        int nums = end - start + 1;
        
        for(int it : arr)
            if(it >= start && it <= end)
                nums--;
        
        return nums == 0;
    }
};
