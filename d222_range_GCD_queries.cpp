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
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    // Get mid index
    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }
    
    // Build segment tree
    int buildSegmentTree(vector<int> &arr, int ss, int se, vector<int> &st, int si) {
        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }
        int mid = getMid(ss, se);
        st[si] = gcd(buildSegmentTree(arr, ss, mid, st, si * 2 + 1),
                     buildSegmentTree(arr, mid + 1, se, st, si * 2 + 2));
        return st[si];
    }
    
    // Query GCD in range
    int findGcd(int ss, int se, int qs, int qe, int si, vector<int> &st) {
        if (ss > qe || se < qs)
            return 0; // neutral for GCD
        if (qs <= ss && qe >= se)
            return st[si];
        int mid = getMid(ss, se);
        return gcd(findGcd(ss, mid, qs, qe, 2 * si + 1, st), findGcd(mid + 1, se, qs, qe, 2 * si + 2, st));
    }
    
    // Update a value in segment tree
    void updateValueUtil(int ss, int se, int index, int new_val, int si, vector<int> &st) {
        if (index < ss || index > se)
            return;
        if (ss == se) {
            st[si] = new_val;
            return;
        }
        int mid = getMid(ss, se);
        if (index <= mid)
            updateValueUtil(ss, mid, index, new_val, 2 * si + 1, st);
        else
            updateValueUtil(mid + 1, se, index, new_val, 2 * si + 2, st);
        st[si] = gcd(st[2 * si + 1], st[2 * si + 2]);
    }
    
    // Wrapper to update value
    void updateValue(int index, int new_val, vector<int> &arr, vector<int> &st, int n) {
        arr[index] = new_val;
        updateValueUtil(0, n - 1, index, new_val, 0, st);
    }

    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        int x = 2 * (int)pow(2, ceil(log2(n))) - 1;
        vector<int> st(x);
        buildSegmentTree(arr, 0, n - 1, st, 0);

        vector<int> result;
        for (auto &query : q) {
            int type = query[0];
            if (type == 1) {
                int index = query[1];
                int new_val = query[2];
                updateValue(index, new_val, arr, st, n);
            }
            else {
                int l = query[1];
                int r = query[2];
                result.push_back(findGcd(0, n - 1, l, r, 0, st));
            }
        }
        
        return result;
    }
};