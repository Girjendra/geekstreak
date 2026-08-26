/*
Given a weighted directed graph containing V vertices numbered from 0 to V - 1 and a list of E directed edges edges[][], determine whether the graph contains a negative weight cycle or not.

Each edge is represented as: [u, v, w], where there is a directed edge from vertex u to vertex v having the given weight w.

Note: A negative-weight cycle is a cycle in a graph whose edges sum to a negative value.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;


// TC : O(V^3) SC : O(V^2)
class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dist(
            V, vector<long long>(V, INF)
        );
    
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
    
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
    
            dist[u][v] = min(dist[u][v], (long long)w);
        }
    
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                if (dist[i][k] == INF) {
                    continue;
                }
    
                for (int j = 0; j < V; j++) {
                    if (dist[k][j] == INF) {
                        continue;
                    }
    
                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }
    
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                return true;
            }
        }
    
        return false;
    }
};


// TC : O(V * E) SC : O(V)
class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<int> dist(V, 0);
        
        for (int i = 0; i < V - 1; i++) {
            bool updated = false;
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
    
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
    
            if (!updated)
                return false;
        }
    
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
    
            if (dist[u] + w < dist[v])
                return true;
        }
    
        return false;
    }
};