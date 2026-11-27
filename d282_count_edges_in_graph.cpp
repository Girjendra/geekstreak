/*
Given an undirected graph with V vertices numbered from 0 to V - 1, represented by an adjacency list adj[][], where adj[i] contains the
vertices adjacent to vertex i.

Return the total number of edges present in the graph.

Examples:
Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3], [2]]
Output: 4
Explanation: The edges in the graph are: (0-1), (0-2), (2-3), (1-2). Hence, total number of edges = 4.

Input: adj[][] = [[1], [0, 2], [1, 3], [2]]
Output: 3
Explanation: The edges in the graph are: (0-1), (1-2), (2-3). Hence, total number of edges = 3.

Constraints:
1 ≤ adj.size() ≤ 10^4
0 ≤ adj[i][j] < adj.size()
*/
#include<iostream>
#include <vector>
#include <set>
using namespace std;








// TC : O(V + E) SC : O(E)
class Solution {
public:
    int countEdges(vector<vector<int>> &adj) {
        set<pair<int, int>> edges;
        
        for(int u = 0; u < adj.size(); u++) {
            for(int v : adj[u])
                edges.insert({u, v});
        }
        
        return edges.size() / 2;
    }
};








// TC : O(V + E) SC : O(1)
class Solution {
public:
    int countEdges(vector<vector<int>> &adj) {
        int ans = 0;
        for(auto neighbors : adj)
                ans += neighbors.size();
        
        return ans / 2;
    }
};