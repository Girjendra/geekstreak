/*
Consider a string s formed by concatenating the decimal representations of all positive integers in order:
s = "12345678910111213141516171819202122232425262728293031..."
Given an integer n, find the nth character (1-based indexing) in the string s.

Examples:
Input: n = 10
Output: '1'
Explanation: The 10th in "1234567891.." character is '1'.

Input: n = 11
Output: '0'
Explanation: The 11th character in "12345678910.."  is '0'.

Constraints:
1 ≤ n ≤ 10^9
*/
#include<iostream>
#include <vector>
#include <cmath>
using namespace std;











// TC : O(n) SC: O(n)
class Solution {
public:
    char nthCharacter(int n) {
        string s = "";
        int num = 1;
    
        while (s.size() < n) {
            s += to_string(num);
            num++;
        }
    
        return s[n - 1];
    }
};









// TC : O(log(n)) SC: O(1)
class Solution {
public:
    char nthCharacter(int n) {
        vector<long long> dig(12, 0);
        for(int i = 1; i <= 11; i++)
            dig[i] = 9LL * pow(10, i - 1) * i;

        int i = 1;
        while(n > dig[i])
            n -= dig[i++];
            
        long long st = pow(10, i - 1);
        long long num = st + (n - 1) / i;
        int digitIndex = (n - 1) % i;
        
        string str = to_string(num);
        return str[digitIndex];
    }
};