/*
Given an array arr[], where arr[i] represents the exact number of steps to move from index i.  An index is considered good if repeatedly following the jumps eventually takes you outside the array. Otherwise, if the jumps result in an infinite loop, the index is considered bad.
A positive value indicates a move to the right
A negative value indicates a move to the left.
A 0 value means no move and considered bad.
Return the number of good indices.

Examples:
Input: [2, 3, -1, 2, -2, 4, 1]
Output: 3
Explanation: Indices 3, 5, and 6 are good because their jump sequences eventually leave the array. Indices 1, 2, and 4 form a cycle, while index 0 eventually enters this cycle through index 2. Hence, the total number of good indices is 3.

Input: [1, 0, -3, 0, -5, 0]
Output: 2
Explanation: Indices 2 and 4 are good because their jumps take them outside the array. Indices 1, 3, and 5 are bad because their jumps are zero. Index 0 is also bad because it jumps to index 1, which is a dead end. Hence, the total number of good indices is 2.

Constraints:
1 ≤ arr.size() ≤ 105
-105 ≤ arr[i] ≤ 105
*/
#include<iostream>
#include <vector>
using namespace std;







// TC : O(n^2) SC: O(n)
class Solution {
public:
    int goodIndices(vector<int> &arr) {
        int n = arr.size();
        vector<bool> ans(n, false);
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++) {
            int j = i;
            vector<bool> tvis(n, false);
            while(true) {
                if(j < 0 || j >= n) {
                    ans[i] = true;
                    break;
                }

                if(tvis[j]) {
                    ans[i] = false;
                    break;
                }

                tvis[j] = true;
                if(arr[j] == 0) {
                    ans[i] = false;
                    break;
                }

                j += arr[j];
            }
        }
        
        int count = 0;
        for(bool is : ans)
            if(is)
                count++;
        
        return count;
    }
};







// TC : O(n) SC: O(n)
class Solution {
public:
    bool dfs(int index, vector<int> &arr, vector<int> &state) {
        int n = arr.size();
        if (index < 0 || index >= n)
            return true;
            
        if (arr[index] == 0)
            return false;
    
        if (state[index] == 2)
            return true;
    
        if (state[index] == 3)
            return false;
    
        if (state[index] == 1)
            return false;
    
        state[index] = 1;
        int nextIndex = index + arr[index];
    
        bool good = dfs(nextIndex, arr, state);
    
        state[index] = good ? 2 : 3;
        return good;
    }
    
    int goodIndices(vector<int> &arr) {
        int n = arr.size();
        int answer = 0;
    
        vector<int> state(n, 0);
        for (int i = 0; i < n; i++)
            if (dfs(i, arr, state))
                answer++;
    
        return answer;
    }
};