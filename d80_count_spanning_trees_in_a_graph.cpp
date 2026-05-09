/*
Given a connected undirected graph with n vertices and m edges, where each edge is represented as
edges[i]=[u,v]  indicating an edge between vertices u and v.
Determine the total number of distinct spanning trees that can be formed from the graph.
Note: A spanning tree is a subgraph of the given graph that includes all n vertices, has exactly
n-1 edges, is connected, and contains no cycles; therefore, every connected undirected graph always
has at least one spanning tree.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    double determinant(vector<vector<double>> mat, int n) {
        double det = 1.0;
    
        for (int i = 0; i < n; i++) {
    
            int pivot = i;
            for (int j = i + 1; j < n; j++) {
                if (fabs(mat[j][i]) > fabs(mat[pivot][i]))
                    pivot = j;
            }
    
            if (fabs(mat[pivot][i]) < 1e-9)
                return 0;
    
            if (i != pivot) {
                swap(mat[i], mat[pivot]);
                det *= -1;
            }
    
            det *= mat[i][i];
            
            for (int j = i + 1; j < n; j++) {
                double factor = mat[j][i] / mat[i][i];
                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }
    
        return det;
    }
    
    int countSpanTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> A(n, vector<int>(n, 0));
        vector<vector<int>> D(n, vector<int>(n, 0));
        
        for(auto ed : edges) {
            int i = ed[0], j = ed[1];
            
            A[i][j] = 1;
            A[j][i] = 1;
        }
        
        for(int i = 0; i < n; i++) {
            int deg = 0;
            for(int it : A[i])
                if(it)
                    deg++;
            
            D[i][i] = deg;
        }
        
        vector<vector<int>> L(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                L[i][j] = D[i][j] - A[i][j];
            }
        }
        
        vector<vector<double>> minor(n - 1, vector<double>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                minor[i][j] = L[i][j];
            }
        }
        
        return round(determinant(minor, n - 1));
    }
};