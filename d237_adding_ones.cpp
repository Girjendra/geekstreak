/*
Consider an array arr[] of size n, initially containing all zeros. You are also given an array updates[] of k positive integers.
For each value j in updates[], add 1 to every element arr[i] whose index satisfies i ≥ j.
The indices in updates[] are 1-based.
Perform all the updates and modify arr[] accordingly.

Examples:
Input: n = 3, updates[] = [1, 1, 2, 3]
Output: [2, 3, 4]
Explanation: Initially, arr[] = [0, 0, 0]. After the first update 1, the array becomes [1, 1, 1]. 
After the second update 1, it becomes [2, 2, 2]. The update 2 increments all elements from index 2 onward, giving [2, 3, 3]. Finally, the update 3 increments the element at index 3, resulting in [2, 3, 4].

Input: n = 2, updates[] = [1, 1, 1]
Output: [3, 3] 
Explanation: Initially the array is [0, 0]. After the first 1, it becomes [1, 1]. 
After the second 1 it becomes [2, 2]. After the third 1, it becomes [3, 3].

Constraints:
1 ≤ n, updates.size() ≤ 10^5
1 ≤ updates[i] ≤ n
*/
#include<iostream>
#include <vector>
using namespace std;







// TC : O(n * K) SC : O(n)
class Solution {
public:
    vector<int> update(int n, vector<int> &updates) {
        vector<int> arr(n, 0);

        for (int j : updates)
            for (int i = j - 1; i < n; i++)
                arr[i]++;

        return arr;
    }
};








// TC : O(n + K) SC : O(n)
class Solution {
public:
    vector<int> update(int n, vector<int>& updates) {
        vector<int> ans(n, 0);
        for(int i : updates)
            ans[i - 1]++;
        
        for(int i = 1; i < n; i++)
            ans[i] += ans[i - 1];
        
        return ans;
    }
};