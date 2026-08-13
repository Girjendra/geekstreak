/*
Given a weighted Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1, represented by edges[][], where edges[i] = [u, v, w] denotes a directed edge from u to v with weight w, and a source vertex src.

Return the distance array, where the value at index i represents the longest distance from s to vertex i.
If a vertex is unreachable from s, store INT_MIN for that vertex. The driver code will automatically display INT_MIN as INF.
*/
#include<iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


// TC : O(2^V)  SC = O(V + E)
class Solution {
  public:
    void solve(unordered_map<int, vector<pair<int,int>>>& adj, vector<int>& ans,
              int curv, int d, int curl, int& mal) {
        
        if(curv == d) {
            mal = max(mal, curl);
            ans[d] = mal;
            return ;
        }
        
        for(auto it : adj[curv])
            solve(adj, ans, it.first, d, curl+it.second, mal);
    }
    
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        
        vector<int> ans(V, INT_MIN);
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v, w});
        }
        
        ans[src] = 0;
        for(int dest = 0; dest < V; dest++) {
            if(src == dest)
                continue;
            
            int ma = INT_MIN;
            solve(adj, ans, src, dest, 0, ma);
        }
        
        return ans;
    }
};


// TC : O(V(V + E))  SC = O(V + E)
class Solution {
  public:
    int solve(unordered_map<int, vector<pair<int,int>>>& adj, int curv, int d, vector<int>& dp) {
        if(curv == d)
            return 0;
        
        if(dp[curv] != INT_MIN)
            return dp[curv];
        
        int maxi = INT_MIN;
        for(auto it : adj[curv]){
            int next = solve(adj, it.first, d, dp);

            if(next != INT_MIN)
                maxi = max(maxi, it.second + next);
        }
            
        return dp[curv] = maxi;
    }
    
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<int> ans(V, INT_MIN);
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto it : edges)
            adj[it[0]].push_back({it[1], it[2]});
        
        ans[src] = 0;
        for(int dest = 0; dest < V; dest++) {
            vector<int> dp(V, INT_MIN);
            
            ans[dest]  = solve(adj, src, dest, dp);
        }
        
        return ans;
    }
};



// TC : O(V + E)  SC = O(V + E)
class Solution {
public:
    void topoDFS(int u,
                 vector<vector<pair<int,int>>>& adj,
                 vector<bool>& vis,
                 vector<int>& topo) {

        vis[u] = true;

        for(auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if(!vis[v])
                topoDFS(v, adj, vis, topo);
        }

        topo.push_back(u);
    }

    vector<int> maxDistance(int V, int src, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<bool> vis(V, false);
        vector<int> topo;

        for(int i = 0; i < V; i++) {
            if(!vis[i])
                topoDFS(i, adj, vis, topo);
        }

        reverse(topo.begin(), topo.end());

        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        for(int u : topo) {

            if(dist[u] == INT_MIN)
                continue;

            for(auto it : adj[u]) {
                int v = it.first;
                int w = it.second;
                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        return dist;
    }
};