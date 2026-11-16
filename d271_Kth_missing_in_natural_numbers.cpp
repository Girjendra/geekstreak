/*
Given an array arr[] of distinct positive integers and a positive integer k. Consider an infinite sequence of natural numbers starting from 1.
The task is to remove all elements present in arr[] from this sequence.
Find the k-th smallest number in the remaining sequence.
Note: Your solution must run in O(1) auxiliary space.

Examples:
Input: arr[] = [1, 9, 5, 2], k = 6
Output: 10
Explanation: After removing [1, 2, 5, 9] from the natural numbers, the remaining sequence is: 3, 4, 6, 7, 8, 10, 11, .... and so on. The 6th
number in this sequence is 10, so the answer is 10.

Input: arr[] = [1, 2, 3, 4], k = 1
Output: 5
Explanation: After removing [1, 2, 3, 4] from the natural numbers, the remaining sequence is: 5, 6, 7, .... and so on. The 1st number in
the sequence is 5, so the answer is 5.

Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i], k ≤ 10^6
All elements of arr are distinct.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;






// TC : (1000000) SC : O(n)
class Solution {
public:
    int findKthSmall(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> temp(1e6 + 1, 1);
        for(int it : arr)
            temp[it] = 0;
            
        int count = 0;
        int elem;
        for(int i = 1; i <= 1e6 + 1; i++) {
            if(temp[i]) {
                count++;
                
                if(count == k)
                    return i;
            }
        }
        
        return 1;
    }
};









// TC : O(nlogn) SC : O(1)
class Solution {
public:
    int findKthSmall(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int prev = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(count + (arr[i] - prev - 1) >= k)
                break;
                
            count += arr[i] - prev - 1;
            prev = arr[i];
        }
        
        while(count < k) {
            count++;
            prev++;
        }
        
        return prev;
    }
};