/*
An IT company is working on a large project consisting of n modules.

The given array time required (in months) to complete the ith module is stored in the array duration[].
The array dependencies[][], where dependencies[i] = [u, v], indicates that module v can be started only after module u is completed. 
Multiple modules can be worked on simultaneously as long as all their dependencies have been completed.

Find the minimum time required to complete the entire project.

If the project cannot be completed due to a cyclic dependency, return -1.
A module is never dependent on itself.

Examples

Input: duration[] = [10, 20, 30, 10, 30, 20], dependencies[][] = [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]
Output: 80

Explanation: 
The Graph of dependency forms this and the project will be completed when Module 1 is completed. The minimum taken time is 80 months, the maximum taken time is through the path 5 -> 2 -> 3 -> 1 which takes 20 + 30 + 10 + 20
Input: duration[] = [5, 5, 5], dependencies[][] = [[0, 1], [1, 2], [2, 0]]
Output: -1
Explanation: There is a cycle in the dependency graph hence the project cannot be completed.

Constraints:
1 ≤ duration.size() ≤ 105
0 ≤ duration[i] ≤ 105
0 ≤ m ≤ 2*105
0 ≤ dependencies[i][j] < 105
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;




// TC : O(n + m) SC : O(n + m) where n is the number of modules and m is the number of dependencies
class Solution {
public:
    int minTime(vector<int> &du, vector<vector<int>> &dep) {
        int n = du.size();
        unordered_map<int, pair<vector<vector<int>>, vector<int>>> m;
        vector<int> hasParent(n, 0);

        for(int i = 0; i < dep.size(); i++) {
            int parent = dep[i][0];
            int child = dep[i][1];

            hasParent[child] = 1;

            m[parent].first.push_back({child, du[child]});
            m[child].second.push_back(parent);
        }

        queue<int> q;
        vector<int> inQueue(n, 0);
        vector<int> completionTime(n, 0);
        for(int i = 0; i < n; i++) {
            if(!hasParent[i]) {
                q.push(i);
                inQueue[i] = 1;
                completionTime[i] = du[i];
            }
        }

        vector<bool> isDone(n, false);
        vector<int> processedParents(n, 0);
        int processedNodes = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            isDone[node] = true;
            processedNodes++;

            for(auto it : m[node].first) {
                int child = it[0];
                completionTime[child] = max(completionTime[child], completionTime[node] + du[child]);

                processedParents[child]++;

                if(processedParents[child] == m[child].second.size()) {

                    if(!inQueue[child]) {
                        q.push(child);
                        inQueue[child] = 1;
                    }
                }
            }
        }

        if(processedNodes != n)
            return -1;

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, completionTime[i]);

        return ans;
    }
};