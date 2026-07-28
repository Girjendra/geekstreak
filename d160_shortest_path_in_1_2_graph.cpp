/*
Given a weighted undirected graph with V vertices numbered from 0 to V - 1, represented by an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi. (wi can only be 1 or 2), and two vertices src and dest, find the shortest distance from src to dest.

The shortest distance is defined as the minimum total weight required to reach dest starting from src.

Return the shortest distance from src to dest. If dest is not reachable from src, return -1.
*/
#include<iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &ed) {
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : ed) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int d = cur.first;
            int u = cur.second;

            if (d > dist[u])
                continue;

            for (auto it : adj[u]) {
                int v = it.first;
                int w = it.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};