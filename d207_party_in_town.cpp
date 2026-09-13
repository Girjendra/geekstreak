/*
Geek Town has n houses numbered from 1 to n, choose a house to host a party such that its distance from its farthest house is as small as possible. Return this minimum possible distance.
The houses are connected by n − 1 bidirectional roads, forming a tree. 
The connections are given as an adjacency list adj, where adj[i] contains all houses directly connected to house i + 1. 
*/
#include<iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;




// TC : O(n^2) SC: O(n)
class Solution {
public:
    int DFS(int node, vector<vector<int>>& adj, vector<int>& vis, int& ans) {
        vis[node] = true;
        
        int cur = 0;
        for(int it : adj[node-1])
            if(!vis[it])
                cur = max(cur, 1 + DFS(it, adj, vis, ans));
                
        return cur;
    }
    
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> md(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            vector<int> vis(n+1, 0);
            int ans = 0;
            md[i] = DFS(i, adj, vis, ans);
        }
        
        md[0] = INT_MAX;
        int ans = INT_MAX;
        for(int it : md)
            ans = min(ans, it);
            
        return ans;
    }
};




// TC : O(n) SC: O(n)
class Solution {
public:
    pair<int, int> BFS(int start, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        pair<int, int> farthest = {0, start};

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int next : adj[node - 1]) {
                if(dist[next] != -1)
                    continue;

                dist[next] = dist[node] + 1;
                q.push(next);

                if(dist[next] > farthest.first)
                    farthest = {dist[next], next};
            }
        }

        return farthest;
    }

    int partyHouse(vector<vector<int>>& adj) {
        auto first = BFS(1, adj);
        auto second = BFS(first.second, adj);
        int diameter = second.first;

        return (diameter + 1) / 2;
    }
};