/*
Given a number n, check whether every bit in the binary representation of the given number is set or not.
Return true if yes, otherwise false.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    bool isBitSet(int n) {
        if(n == 0)
            return false;
        else
            return (n & (n+1)) == 0;
    }
};