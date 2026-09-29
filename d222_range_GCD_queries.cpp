/*
Given an integer array arr[] and a 2D array queries[][] containing q queries, where each query is one of the following two types:

Type 1: [0, l, r] -> Return the GCD of all elements in the range [l, r] (both inclusive).
Type 2: [1, index, value] -> Update arr[index] to value.
Return an array containing the answers to all Type 1 queries in the order they appear in queries[][].
Note: Use 0-based indexing.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ q ≤ 105
0 ≤ l, r, index ≤ arr.size()-1
1 ≤ arr[i], value ≤ 105
*/
#include<iostream>
#include <vector>
#include <cmath>
using namespace std;




// TC : O(q * n)
class Solution {
  public:
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int> ans;
        for(auto it : q) {
            if(it[0] == 1)
                arr[it[1]] = it[2];
            else {
                int l = it[1];
                int r = it[2];
                int gcd = arr[l];
                for(int i = l + 1; i <= r; i++)
                    gcd = findGCD(gcd, arr[i]);
                    
                ans.push_back(gcd);
            }
        }    
        
        return ans;
    }
};






// TC : O(q * log(n))
class Solution {
  public:
    int gcd(int a, int b) {
        if(b == 0)
            return a;
    
        return gcd(b, a % b);
    }
    
    void buildTree(vector<int>& arr, vector<int>& segTree, int index, int st, int end) {
        if(st == end) {
            segTree[index] = arr[st];
            return ;
        }
        
        int mid = st + (end - st) / 2;
        buildTree(arr, segTree, 2 * index + 1, st, mid);
        buildTree(arr, segTree, 2 * index + 2, mid + 1, end);
        
        segTree[index] = gcd(segTree[2 * index + 1], segTree[2 * index + 2]);
    }
    
    int query(vector<int>& segTree, int index, int st, int end, int l, int r) {
        if(r < st || end < l)
            return 0;
            
        if(l <= st && end <= r)
            return segTree[index];
            
        int mid = st + (end - st) / 2;
        int left = query(segTree, 2 * index + 1, st, mid, l, r);
        int right = query(segTree, 2 * index + 2, mid + 1, end, l, r);
        
        return gcd(left, right);
    }
    
    void update(vector<int>& arr, vector<int>& segTree, int index, int i, int st, int end, int value) {
        if(i < st || i > end)
            return ;
            
        if(st == end) {
            arr[i] = value;
            segTree[index] = value;
            return ;
        }
        
        int mid = st + (end - st) / 2;
        update(arr, segTree, 2 * index + 1, i, st, mid, value);
        update(arr, segTree, 2 * index + 2, i, mid + 1, end, value);
        
        
        segTree[index] = gcd(segTree[2 * index + 1], segTree[2 * index + 2]);
    }
    
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
    
        int treesize = 2*(int)pow(2, ceil(log2(n))) - 1; // or treesize = 4 * n
        vector<int> segTree(treesize);
        
        buildTree(arr, segTree, 0, 0, n - 1);
        
        vector<int> ans;
        for(auto it : q) {
            if(it[0] == 0) {
                int l = it[1];
                int r = it[2];
                int index = 0;
                ans.push_back(query(segTree, index, 0, n - 1, l, r));
            }
            else {
                int index = 0;
                int i = it[1];
                int value = it[2];
                update(arr, segTree, index, i, 0, n - 1, value);
            }
        }
        
        return ans;
    }
};