/*
Given an array arr[] containing integers from 1 to n exactly once, sort the array in ascending order.

In one operation, you can pick any element and move it either to the beginning or to the end of the array.

Return the minimum number of operations required to sort the array.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &arr) {
        int n = arr.size();
        int count[n + 1] = {0};

        for (int x : arr) {
            if (count[x - 1] != 0)
                count[x] = count[x - 1] + 1;
            else
                count[x] = 1;
        }

        int longest = 0;

        for (int i = 0; i <= n; ++i) {
            longest = max(longest, count[i]);
        }

        return n - longest;
    }
};