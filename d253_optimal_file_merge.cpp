/*
Given an integer array files[], where files[i] represents the size of the i-th file, merge all the files into a single file with the
minimum total computation cost.
The cost of merging two files of sizes x and y is x + y. After merging, a new file of size x + y is created, which can be merged further
with other files.
Return the minimum total cost required to merge all the files.
Note: It is guaranteed that the minimum total computation cost fits within a 32-bit signed integer.

Examples:
Input: files[] = [3, 2, 4]
Output: 14
Explanation: There are different ways to combine these files. Optimal method is given below:

Input: files[] = [2, 3, 6, 5, 7, 4]
Output: 68
Explanation: There are different ways to combine these files. Optimal method is given below:

Constraints:
1 ≤ files.size() ≤ 10^5
1 ≤ files[i] ≤ 103
*/
#include<iostream>
#include <queue>
using namespace std;









// TC : O(nlogn) SC : O(n)
class Solution {
public:
    int minComputation(vector<int> &files) {
        priority_queue<int, vector<int>, greater<int>> que;
        
        for(int it : files)
            que.push(it);
        
        int ans = 0;
        while(que.size() > 1) {
            int min1 = que.top();
            que.pop();
            int min2 = que.top();
            que.pop();
            
            ans += (min1 + min2);
            que.push(min1 + min2);
        }
        
        return ans;
    }
};