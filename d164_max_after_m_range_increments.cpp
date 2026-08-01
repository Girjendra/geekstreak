/*
Given three arrays a[], b[], and k[], representing m range increment operations on an array arr[] of size n, where all elements of arr[] are initially 0.

Increment(a[i], b[i], k[i]) adds k[i] to each element arr[j] such that a[i] ≤ j ≤ b[i] (mainly indexes in range from a[i] to b[i])
After performing all the given operations, find the maximum value present in the array.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        vector<int> arr(n + 1, 0);
        for (int i = 0; i < a.size(); i++) {
            int lowerbound = a[i];
            int upperbound = b[i];
    
            arr[lowerbound] += k[i];
    
            if (upperbound + 1 < arr.size())
                arr[upperbound + 1] -= k[i];
        }
    
        int sum = 0, res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            res = max(res, sum);
        }
        
        return res;
    }
};