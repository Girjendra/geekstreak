/*
Given an undirected graph with V vertices numbered from 0 to V - 1, represented by an adjacency list adj[][], where adj[i]
contains all vertices adjacent to vertex i. Also given two vertices u and v, check whether a path exists between them.
Return true if a path exists, otherwise return false.

Examples:
Input: adj[][] = [[2, 3], [2], [0, 1], [0], [5], [4]], u = 1, v = 5
420046859
Output: false
Explanation: There is no path from vertex 1 to vertex 5.

Input: adj[][] = [[2, 3], [2], [0, 1], [0], [5], [4]], u = 2, v = 3
420046859
Output: true
Explanation: We can reach vertex 3 from vertex 2 via vertex 0.
1

Constraints:
2 ≤ adj.size() ≤ 10^5
0 ≤ adj[i][j], u, v < adj.size()
u != v
*/
#include<iostream>
#include <vector>
#include <queue>
using namespace std;








class Solution {
public:
    bool DFS(int node, int v, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[node] = true;
        for(int it : adj[node]) {
            if(it == v)
                return true;
                
            if(!vis[it] && DFS(it, v, vis, adj))
                return true;
        }
        
        return false;
    }
    
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        int n = adj.size();

        vector<bool> vis(n, false);
        return  DFS(u, v, vis, adj);
    }
};








class Solution {
public:
    bool BFS(int u, int v, vector<vector<int>> &adj) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;
    
        visited[u] = true;
        q.push(u);
    
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
    
            if (curr == v) return true;
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    
        return false;
    }

    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        return  BFS(u, v, adj);
    }
};