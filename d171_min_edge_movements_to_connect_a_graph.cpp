/*
Given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operations required to connect the graph. If it is not possible to connect the graph, return -1.
*/
#include<iostream>
#include <map>
#include <vector>
using namespace std;

// TC : O(n + m) where n is the number of vertices and m is the number of edges
class Solution {
  public:
    void DFS(int i, map<int, vector<int>>& adj, vector<bool>& vis) {
        vis[i] = true;
        
        for(int n : adj[i]) {
            if(!vis[n])
                DFS(n, adj, vis);
        }
    }
    
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> adj;
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int comp = 0;
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                comp++;
                DFS(i, adj, vis);
            }
        }
        
        int m = edges.size();
        int extra = m - (n - comp);
        
        if(extra >= comp - 1)
            return comp - 1;
        else
            return -1;
    }
};