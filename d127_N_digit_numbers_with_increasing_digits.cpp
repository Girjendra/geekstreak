/*
Given an integer n, return all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void generateNumbers(int remainingDigits, int currentDigit, int currentNumber, vector<int> &result) {
        if (remainingDigits == 0) {
            result.push_back(currentNumber);
            return;
        }
    
        for (int nextDigit = currentDigit + 1; nextDigit <= 9; nextDigit++) {
            generateNumbers(remainingDigits - 1, nextDigit, currentNumber * 10 + nextDigit, result);
        }
    }
    
    vector<int> increasingNumbers(int n) {
        vector<int> result;
    
        if (n == 1) {
            for (int digit = 0; digit <= 9; digit++)
                result.push_back(digit);
    
            return result;
        }
    
        if (n > 9)
            return result;
    
        for (int firstDigit = 1; firstDigit <= 9; firstDigit++) {
            generateNumbers(n - 1, firstDigit, firstDigit, result);
        }
    
        return result;
    }
};