/*
You are given an array arr[] of size n. You need to remove a subarray of size k , such that the difference
between the maximum and minimum values of the remaining array is minimized. Find the minimum value obtained
after performing the operation of the removal of the subarray.

Examples:
Input: arr = [1, 2, 3, 4, 5], k = 3 
Output: 1
Explanation: We remove first subarray of length 3, the remaining array is [4,5] and the difference of maximum
and minimum element is 1 i.e 5 - 4 = 1

Input: arr = [2, 3, 1, 4, 6, 7], k = 3
Output: 2
Explanation: 
If we remove the subarray [2,3,1] then remaining array is [4,6,7] and the difference  = 7-4 = 3
If we remove the subarray [3,1,4] then remaining array is [2,6,7] and the difference  = 7-2 = 5
If we remove the subarray [1,4,6] then remaining array is [2,3,7] and the difference  = 7-2 = 5
If we remove the subarray [4,6,7] then remaining array is [2,3,1] and the difference  = 3-1 = 2
So the answer is min(3,5,5,2) = 2

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 109
0 ≤ k < arr.size()
*/
#include<iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;







// TC : O(n^2): SC : O(1)
class Solution {
public:
    int minDiff(int k, vector<int> &arr) {
        int n = arr.size();
        int res = INT_MAX;
    
        for (int i = 0; i <= n - k; i++) {
            int mn = INT_MAX;
            int mx = INT_MIN;
            for (int j = 0; j < n; j++) {
                if (j >= i && j < i + k)
                    continue;
    
                mn = min(mn, arr[j]);
                mx = max(mx, arr[j]);
            }
    
            res = min(res, mx - mn);
        }
    
        return res;
    }
};







// TC : O(n*logn)  SC :O(1)
class Solution {
public:
    int minDiff(int k, vector<int> &arr) {
        int n = arr.size();
        
        multiset<int> mySet;
        for(int i = k; i < n; i++)
            mySet.insert(arr[i]);
        
        int i = 0;
        int j = k - 1;
        int ans = INT_MAX;
        for(int m = k; m < n; m++) {
            ans = min(ans, *mySet.rbegin() - *mySet.begin());
        
            mySet.erase(mySet.find(arr[m]));
            mySet.insert(arr[i]);
            i++;
            j++;
        }
        
        ans = min(ans, *mySet.rbegin() - *mySet.begin());
        return ans;
    }
};