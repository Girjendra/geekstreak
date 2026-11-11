/*
Given an array of integers, arr[] and an integer k, check whether there exist two distinct indices i and j such that arr[i] is
equal to arr[j] and the absolute difference between i and j is at most k.

Examples:
Input: arr[] = [1, 5, 4, 5, 1], k = 3
Output: true
Explanation: The element 5 occurs at indices 1 and 3. Their distance is |3 - 1| = 2, which is less than or equal to k.

Input: arr[] = [10, 2, 3, 4, 10, 5], k = 3
Output: false
Explanation: The element 10 occurs at indices 0 and 4. Their distance is |4 - 0| = 4, which is greater than k. Hence, no duplicate
exists within the given distance.

Input: arr[] = [5, 1, 3, 2, 4], k = 3
Output: false
Explanation: All elements are distinct, so no duplicate exists.

Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
1 ≤ k < arr.size()
*/
#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;







// TC : O(n*k) SC : O(1)
class Solution {
public:
    bool checkWithinK(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int c = 1; c <= k && (i + c) < n; c++) {
                int j = i + c;

                if (arr[i] == arr[j])
                    return true;
            }
        }
        
        return false;
    }
};








// TC : O(n) SC : O(k)
class Solution {
public:
    bool checkWithinK(vector<int>& arr, int k) {
        unordered_set<int> s;
        for (int i = 0; i < arr.size(); i++) {
            if (s.find(arr[i]) != s.end())
                return true;

            s.insert(arr[i]);
            if (i >= k)
                s.erase(arr[i - k]);
        }

        return false;
    }
};