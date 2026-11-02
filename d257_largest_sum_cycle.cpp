/*
Given an array edge[] of size n, there are n cells numbered from 0 to n - 1. Each cell has at most
one outgoing edge.
For every cell i:
edge[i] is the cell reached from i in one step.
edge[i] = -1 means that cell i has no outgoing edge.
A cycle is a sequence of cells where, by following the outgoing edges, we eventually return to the
starting cell. The sum of a cycle is the sum of the indices of all cells in that cycle.
Return the maximum cycle sum. If there is no cycle, return -1.

Examples:
Input: edge[] = [1, 2, 0, -1]
Output: 3
Explanation: There is only one cycle in the graph i.e. 0 -> 1 -> 2 -> 0. Sum of the cell index in
that cycle = 0 + 1 + 2 = 3.

Input: edge[] = [2, 0, -1, 2]
Output: -1
Explanation: There is no cycle in the graph. The edges are 1 -> 0 -> 2 <- 3. Hence, 2 has no outgoing
edge, so no cycle exists.

Constraints:
2 ≤ edge.size() ≤ 10^5
-1 ≤ edge[i] < edge.size()
edge[i] != i
*/
#include<iostream>
#include <vector>
using namespace std;







// TC : O(n^2) SC: O(n)
class Solution {
public:
    int largestSumCycle(vector<int>& ed) {
        int n = ed.size();
    
        int ans = -1;
        for(int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            int sum = 0;
            int st = i;
            while(st != -1 && !vis[st]) { 
                vis[st] = true;
                st = ed[st];
            }
            
            if(st != -1 && vis[st]) {
                int sum = 0;
                int cur = st;
                
                do {
                    sum += cur;
                    cur = ed[cur];
                } while(cur != st);
                
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};









// TC : O(n^2) SC: O(n)
class Solution {
public:
    void DFS(vector<int>& ed, vector<bool>& vis, int& ans, int cursum, int i) {
        if(ed[i] == -1)
            return ;
            
        if(vis[i]) {
            int sum = 0;
            int cur = i;

            do {
                sum += cur;
                cur = ed[cur];
            } while(cur != i);

            ans = max(ans, sum);
            return ;
        }
        
        vis[i] = true;
        DFS(ed, vis, ans, cursum + i, ed[i]);
        vis[i] = false;
    }
    
    int largestSumCycle(vector<int>& ed) {
        int n = ed.size();
    
        vector<bool> vis(n, false);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(!vis[i])
                DFS(ed, vis, ans, 0, i);
        }
        
        return ans;
    }
};









// TC : O(n) SC: O(n)
class Solution {
public:
    void DFS(vector<int>& ed, vector<bool>& vis, vector<bool>& pathVis,
                            vector<int>& pathSum, int i, int curSum, int& ans) {
        if(i == -1) return;
    
        if(pathVis[i]) {
            ans = max(ans, curSum - pathSum[i]);
            return;
        }

        if(vis[i]) return;

        vis[i] = true;
        pathVis[i] = true;
        pathSum[i] = curSum;
    
        DFS(ed, vis, pathVis, pathSum, ed[i], curSum + i, ans);
        pathVis[i] = false;
    }
    
    int largestSumCycle(vector<int>& ed) {
        int n = ed.size();
        vector<bool> vis(n, false);
        vector<bool> pathVis(n, false);
        vector<int> pathSum(n, 0);
        
        int ans = -1;
        for(int i = 0; i < n; i++)
            if(!vis[i])
                DFS(ed, vis, pathVis, pathSum, i, 0, ans);
        
        return ans;
    }
};