/*
Given an integer array arr[], find the XOR of the XOR values of all possible non-empty subarrays of the array.

Examples:
Input: arr[] = [1, 2, 3] 
Output: 2
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result: 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2

Input: arr[] = [1, 2]
Output: 0
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2] = 2
Result: 1 ^ 3 ^ 2 = 0

Constraints:
1 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^9
*/
#include<iostream>
#include <vector>
#include <map>
using namespace std;






// TC : O(n^2), SC: O(1)
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        int XOR = 0;
        
        for(int i = 0; i < n; i++) {
            int curXOR = 0;
            for(int j = i; j < n; j++) {
                curXOR ^= arr[j];
                XOR ^= curXOR;
            }
        }
        
        return XOR;
    }
};







// TC : O(n), SC: O(n)
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        map<int, long long> fre;
        
        for(int i = 0; i < n; i++) {
            fre[arr[i]] += 1LL * (i + 1) * (n - i);
            fre[arr[i]] %= 2;
        }
        
        int XOR = 0;
        for(auto it : fre)
            if(it.second == 1)
                XOR ^= it.first;

        return XOR;
    }
};







// TC : O(n), SC: O(1)
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int result = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++)
            if ((i + 1) % 2 != 0 && (n - i) % 2 != 0)
                result ^= arr[i];
        
        return result;
    }
};