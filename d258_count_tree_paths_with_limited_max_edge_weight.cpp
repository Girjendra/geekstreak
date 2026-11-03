/*
Given a weighted tree with n nodes, numbered from 1 to n and n - 1 edges, where each edge is represented as [u, v, w]
indicating an edge between nodes u and v with weight w.
You are also given an array queries[], where each queries[i] represents a maximum allowed edge weight.
For each query x, find the number of distinct paths in the tree such that the maximum edge weight along the path is less
than or equal to x.
Return an array containing the number of valid paths for each query.

Note:
A path from node u to node v and the path from node v to node u are considered the same path.
A path must contain at least one edge. A path from a node to itself is not considered.

Examples:
Input: n = 3, edges[][] = [[1, 2, 1], [2, 3, 4]], queries[] = [3]
Output: [1]
Explanation:
For x = 3, only the edge [1, 2, 1] has weight less than or equal to 3.
Therefore, the only valid path is: 1 -> 2
The path 1 -> 3 contains an edge of weight 4, so it is not valid.
Hence, the answer is 1.

Input: n = 7, edges[][] = [[1, 2, 3], [2, 3, 1], [2, 4, 9], [3, 6, 7], [3, 5, 8], [5, 7, 4]], queries[] = [1, 3, 5]
Output: [1, 3, 4]
Explanation: For x = 1, only the edge [2, 3, 1] satisfies the condition. 
Therefore, the only valid path is 2 -> 3, giving an answer of 1.
For x = 3, the edges [2, 3, 1] and [1, 2, 3] can be used. 
They form three valid paths: 1 -> 2, 2 -> 3, and 1 -> 3. 
For x = 5, the edges with weights 1, 3, and 4 can be used. 
They form four valid paths: 1 -> 2, 2 -> 3, 1 -> 3, and 5 -> 7.

Constraints:
2 ≤ n ≤ 10^4
1 ≤ queries.size() ≤ 10^4
0 ≤ queries[i] ≤ 10^5
edges.size() = n-1
edges[i].size() = 3
1 ≤ edges[i][0], edges[i][1] ≤ n
edges[i][0] != edges[i][1]
0 ≤ edges[i][2] ≤ 10^5
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;







//  TC : O(nlogn + qlogq)  SC: O(n)
class Solution {
public:
    int find(int x, vector<int>& parent) {
        if(parent[x] == x)
            return x;
            
        return parent[x] = find(parent[x], parent);
    }
    
    void unionset(int u, int v, vector<int>& size, vector<int>& parent) {
        int uparent = find(u, parent);
        int vparent = find(v, parent);
        
        if(size[uparent] < size[vparent]) {
            swap(uparent, vparent);
        }
        
        parent[vparent] = uparent;
        size[uparent] += size[vparent];
    }
    
    vector<int> maximumWeight(int n, vector<vector<int>> ed, vector<int>& q) {
        vector<pair<int,int>> queries;
        for(int i = 0; i < q.size(); i++)
            queries.push_back({q[i], i});
        
        sort(queries.begin(), queries.end());
        vector<int> ans(q.size(), 0);
        
        sort(ed.begin(), ed.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        
        vector<int> parent(n + 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
        
        vector<int> size(n + 1, 1);
        int j = 0;
        long long paths = 0;
        for(int i = 0; i < q.size(); i++) {
            int query = queries[i].first;
            int originalIndex = queries[i].second;
                
            while(j < n - 1 && ed[j][2] <= query) {
                int u = ed[j][0];
                int v = ed[j][1];
                
                int uparent = find(u, parent);
                int vparent = find(v, parent);
                
                if(uparent != vparent) {
                    paths += 1LL * size[uparent] * size[vparent];
                    unionset(u, v, size, parent);
                }
                
                j++;
            }
            
            ans[originalIndex] = paths;
        }
        
        return ans;
    }
};