/*
Given a number n, find whether n can be expressed as sum of two or more consecutive positive numbers.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        if (n == 1)
            return false;
    
        if ((n & (n - 1)) == 0)
            return false;
    
        return true;
    }
};