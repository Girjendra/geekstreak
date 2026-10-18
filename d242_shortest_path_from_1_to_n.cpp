/*
Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j
if and only if either j = i + 1 or j = 3 * i. The task is to find the minimum number of edges in a path from vertex 1 to vertex n.

Examples:
Input: n = 4
Output: 2
Explanation: Possible paths from 1 to 4 are, 1 -> 2 -> 3 -> 4 and 1 -> 3 -> 4. Second path of length 2 is the shortest.

Input: n = 9
Output: 2
Explanation: Many paths are possible from 1 to 9. Shortest one possible is, 1 -> 3 -> 9, of length 2.

Input: n = 15
Output: 4
Explanation: Many paths are possible from 1 to 15. Shortest one possible is, 1 -> 3 -> 4 -> 5 -> 15, of length 4.

Constraints:
1 ≤ n ≤ 108
*/
#include<iostream>
#include <climits>
#include <vector>
using namespace std;







// TC : O(2^n) SC : O(n)
class Solution {
public:   
    int solve(int cur, int n) {
        if(cur == n)
            return 0;
        
        int ans = INT_MAX;
        if(cur + 1 <= n)
            ans = min(ans, 1 + solve(cur + 1, n));
            
        if(cur * 3 <= n)
            ans = min(ans, 1 + solve(cur * 3, n));
            
        return ans;
    }
    
    int minimumStep(int n) {
        return solve(1, n);
    }
};









// TC : O(n) SC : O(n)
class Solution {
public:
    int minimumStep(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;

        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i], 1 + dp[i - 1]);
            if(i % 3 == 0)
                dp[i] = min(dp[i], 1 + dp[i / 3]);
        }
        
        return dp[n];
    }
};








// TC : O(logn) SC : O(1)
class Solution {
public:
    int minimumStep(int n) {
        int ans = 0;
        while(n > 1) {
            if(n % 3 == 0)
                n /= 3;
            else
                n--;
            ans++;
        }
        
        return ans;
    }
};