/*
Given an integer array arr[] where the two parts around a break point are individually sorted,
merge them into a single sorted array.  The break point can be anywhere in the array, including at
the beginning or end.

Examples:
Input: arr[] = [2, 3, 8, -1, 7, 10]
Output: [-1, 2, 3, 7, 8, 10] 
Explanation: [2, 3, 8] and [-1, 7, 10] are sorted in the original array. The overall sorted version is [-1 2 3 7 8 10].

Input: arr[] = [-4, 6, 9, -1, 3]
Output: [-4, -1, 3, 6, 9]
Explanation: [-4, 6, 9] and [-1, 3] are sorted in the original array. The overall sorted version is [-4 -1 3 6 9].

Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: One part is empty and the other part is whole array which is already sorted.

Constraints:
1 ≤ arr.size() ≤ 106
-105 ≤ arr[i] ≤ 105
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;






// TC : O(n)  SC: O(n)
class Solution {
public:
    void mergeTwoParts(vector<int>& arr) {
        int ind = -1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i - 1] > arr[i]) {
                ind = i - 1;
                break;
            }
        }
        
        if(ind == -1)
            return ;
        
        int i = 0;
        int m = 0;
        int n = ind + 1;
        vector<int> ans(arr.size());
        
        while(m <= ind && n < arr.size()) {
            if(arr[m] < arr[n])
                ans[i++] = arr[m++];
            else
                ans[i++] = arr[n++];
        }
        
        while(m <= ind)
            ans[i++] = arr[m++];
            
        while(n < arr.size())
            ans[i++] = arr[n++];
            
        arr = ans;
    }
};







// TC : O(nlogn)  SC: O(1)
class Solution {
public:
    void mergeTwoParts(vector<int>& arr) {
        sort(arr.begin(), arr.end());
    }
};