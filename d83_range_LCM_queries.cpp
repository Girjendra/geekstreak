/*
Given an array arr[]  and a list of queries queries[][]. Each query can be one of the following two types:
Update Query: [1, index, value] --> Update the element at position index in the array to the given value.
Range Query: [2, L, R] --> Compute and return the Least Common Multiple (LCM) of all elements in the
subarray from index L to R (inclusive).
Process all queries sequentially and return a list containing the results of all Type 2 queries.

Note: All operations follow 0-based indexing.
*/
#include<iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
    
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

class SegmentTree {
  private:
    vector<long long> tree;
    vector<int> arr;
    int n;

  public:
    SegmentTree(vector<int> input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

  
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }
      
        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {
        if (end < l || start > r)
            return 1;
            
        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        long long left = query(2 * node, start, mid, l, r);
        long long right = query(2 * node + 1, mid + 1, end, l, r);
        
        return lcm(left, right);
    }
};

class Solution {
  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        SegmentTree st(arr);
    
        vector<long long> result;
    
        for (auto &q : queries) {
            int type = q[0];
    
            if (type == 1) {
                int idx = q[1];
                int val = q[2];
    
                st.update(1, 0, arr.size() - 1, idx, val);
            }
            else {
                int l = q[1];
                int r = q[2];
    
                long long ans = st.query(1, 0, arr.size() - 1, l, r);
                result.push_back(ans);
            }
        }

        return result;
    }
};