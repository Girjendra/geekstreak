/*
Given two integers l and r, find the bitwise XOR of all integers in the range [l, r] (both inclusive).

Examples:
Input: l = 4, r = 8 
Output: 8 
Explanation: The XOR of all integers from 4 to 8 is (4 xor 5 xor 6 xor 7 xor 8) = 8.

Input: l = 2, r = 4
Output: 5
Explanation: The XOR of all integers from 2 to 4 is (2 xor 3 xor 4) = 5.

Input: l = 5, r = 9
Output: 5
Explanation: The XOR of all integers from 5 to 9 is (5 xor 6 xor 7 xor 8 xor 9) = 5.

Constraints:
1 ≤ l ≤ r ≤ 10^9
*/
#include<iostream>
using namespace std;








// TC : O(1) SC : O(1)
class Solution {
public:
    int findXOR(int l, int r) {
        int lxor;
        l--;
        if(l % 4 == 0)
            lxor = l;
        else if(l % 4 == 1)
            lxor = 1;
        else if(l % 4 == 2)
            lxor = l + 1;
        else
            lxor = 0;
            
        int rxor;
        if(r % 4 == 0)
            rxor = r;
        else if(r % 4 == 1)
            rxor = 1;
        else if(r % 4 == 2)
            rxor = r + 1;
        else
            rxor = 0;
            
        return (lxor ^ rxor);
    }
};