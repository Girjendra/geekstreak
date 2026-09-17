/*
Given a directed graph with n vertices numbered from 1 to n. The graph is represented using a 2D array edges[][] of size m, where each entry edges[i] = [u, v] denotes a directed edge from vertex u to vertex v. You are also given a source vertex src and a destination vertex dst.

Find the minimum number of edges that need to be reversed so that there exists at least one path from src to dst.

If it is not possible to create a path from src to dst, return -1.

Constraints:
1 ≤ n, m ≤ 105
1 ≤ edges[i][0], edges[i][1] ≤ n
1 ≤ src, dst ≤ n
*/
#include<iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;




// TC : O((V + E) log V)
class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
    
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
    
        dist[src] = 0;
        pq.push({0, src});
    
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
    
            if (d != dist[node])
                continue;
    
            for (auto& edge : adj[node]) {
                int next = edge.first;
                int cost = edge.second;
    
                if (d + cost < dist[next]) {
                    dist[next] = d + cost;
                    pq.push({dist[next], next});
                }
            }
        }
    
        if (dist[dst] == INT_MAX)
            return -1;
    
        return dist[dst];
    }
};