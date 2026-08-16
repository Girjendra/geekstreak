/*
Given an integer array arr[], find the minimum possible product that can be obtained by multiplying the elements of any non-empty subset of the array.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;

// TC : O(2^n) where n is the size of the array
class Solution {
public:
    long long solve(int i, long long product, vector<int>& arr, bool taken) {
        if(i == arr.size()) {
            if(taken)
                return product;
            return LLONG_MAX;
        }

        long long yes = solve(i + 1, product * arr[i], arr, true);
        long long no = solve(i + 1, product, arr, taken);

        return min(yes, no);
    }

    int minProd(vector<int>& arr) {
        return (int)solve(0, 1, arr, false);
    }
};