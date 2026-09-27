/*

*/
#include<iostream>
#include <vector>
using namespace std;





// TC : O(n^2) SC: O(n)
class Solution {
  public:   
// DFS to find all valid paths starting from the current node
void dfs(vector<vector<int>> &adj, string &s, 
        int node, int par, bool blueStarted, int len, int &res)
    {
        // Update the maximum path length
        res = max(res, len);

        for (int it : adj[node])
        {
            if (it == par)
                continue;

            // A Red node cannot be visited after a Blue node
            if (blueStarted && s[it] == 'R')
                continue;

            // Update whether the path has entered Blue nodes
            bool nextBlueStarted = blueStarted || (s[it] == 'B');

            dfs(adj, s, it, node, nextBlueStarted, len + 1, res);
        }
    }

    int longestPath(string& s, vector<vector<int>>& edges) {
        int n = s.size();

        // Build the adjacency list
        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int res = 1;

        // Try every node as the starting node
        for (int i = 0; i < n; i++)
        {
            bool blueStarted = (s[i] == 'B');

            // Find all valid paths starting from node i
            dfs(adj, s, i, -1, blueStarted, 1, res);
        }

        return res;
    }
};







// TC : O(n) SC: O(n)
class Solution {
  public:   
    void root(vector<vector<int>> &adj, string &s, 
            vector<vector<int>> &sa, int node = 0, int par = -1)
    {
        int ra = 0, ba = 0;

        // Process all children of the current node.
        for (auto &it : adj[node])
        {
            if (it == par)
                continue;

            // Calculate DP values for the child subtree.
            root(adj, s, sa, it, node);

            // Store the maximum possible contribution
            // for a path ending at a Red node.
            ra = max(ra, sa[it][0]);
            ra = max(ra, sa[it][1]);

            // Store the maximum possible contribution
            // for a path ending at a Blue node.
            ba = max(ba, sa[it][1]);
        }

        // Calculate the DP values based on the
        // color of the current node.
        if (s[node] == 'R')
        {
            sa[node][0] = ra + 1;
            sa[node][1] = 0;
        }
        else
        {
            sa[node][0] = ba + 1;
            sa[node][1] = ba + 1;
        }
    }

    // Reroot the tree to include contributions
    // coming from the parent and sibling subtrees.
    void reroot(vector<vector<int>> &adj, string &s, vector<vector<int>> &ans, 
                vector<vector<int>> &sa, int node = 0, int par = -1, 
                int red_par = 0, int blue_par = 0)
    {
        // Calculate the best answer for the current node
        // by considering both subtree and parent contributions.
        if (s[node] == 'R')
        {
            ans[node][0] = max(sa[node][0], 1 + red_par);
            ans[node][1] = 0;
        }
        else
        {
            ans[node][0] = max(sa[node][0], 1 + blue_par);
            ans[node][1] = max(sa[node][1], 1 + blue_par);
        }

        // Find the largest and second-largest contributions
        // from all child subtrees.
        int fr = red_par, sr = red_par;
        int fb = blue_par, sb = blue_par;

        for (auto &it : adj[node])
        {
            if (it == par)
                continue;

            // Maintain the two largest Red contributions.
            if (sa[it][0] > fr)
            {
                sr = fr;
                fr = sa[it][0];
            }
            else if (sa[it][0] > sr)
            {
                sr = sa[it][0];
            }

            // Maintain the two largest Blue contributions.
            if (sa[it][1] > fb)
            {
                sb = fb;
                fb = sa[it][1];
            }
            else if (sa[it][1] > sb)
            {
                sb = sa[it][1];
            }
        }

        // Pass the best contribution excluding the current child
        // while rerooting the tree at every child.
        for (auto &it : adj[node])
        {
            if (it == par)
                continue;

            int new_red = 0, new_blue = 0;

            if (s[node] == 'R')
            {
                // Use the best Red contribution
                // that does not come from this child.
                new_red = 1;

                if (sa[it][0] == fr)
                    new_red += sr;
                else
                    new_red += fr;

                new_blue = 0;
            }
            else
            {
                // Use the best Blue contribution
                // that does not come from this child.
                new_red = 1;

                if (sa[it][1] == fb)
                    new_red += sb;
                else
                    new_red += fb;

                new_blue = new_red;
            }

            // Reroot the tree at the current child.
            reroot(adj, s, ans, sa, it, node, new_red, new_blue);
        }
    }
    
    int longestPath(string& s, vector<vector<int>>& edges) {
        int n = s.size();

        // Build the adjacency list of the tree.
        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }

        // Index 0 represents Red and index 1 represents Blue.
        vector<vector<int>> subTreeAns(n, vector<int>(2));

        // Calculate DP values using a bottom-up traversal.
        root(adj, s, subTreeAns);

        vector<vector<int>> ans(n, vector<int>(2));

        // Reroot the tree to consider paths in all directions.
        reroot(adj, s, ans, subTreeAns);

        int res = 0;

        // Find the maximum valid path length.
        for (int i = 0; i < n; i++)
            res = max({res, ans[i][0], ans[i][1]});

        return res;
    }
};