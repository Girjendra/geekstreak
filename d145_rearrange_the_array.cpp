/*
Consider an array a[] = [1, 2, 3, ..., n] and a permutation b[] of size n containing all integers from 1 to n exactly once.

The array b[] defines a rearrangement operation.
During a single operation, every element at position i in a[] moves to position b[i] (1-based indexing).
We must do at least one operation on a[].
Find the minimum number of operations required for all elements to return to their original positions simultaneously, i.e., for a[] to become: [1, 2, 3, ..., n] again.

Note:  The answer can be large, so return the answer modulo 10^9+7.
*/
#include<iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
  public:
    bool isOriginal(vector<int> &a) {
        int n = a.size();
        for (int i = 0; i < n; i++)
            if (a[i] != i + 1)
                return false;
    
        return true;
    }

    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<int> a(n); 
        iota(a.begin(), a.end(), 1);
        
        int ans = 0;
        int MOD = 1000000007;
        
        while(true) {
            vector<int> temp(n);

            for (int i = 0; i < n; i++)
                temp[b[i] - 1] = a[i];
    
            a = temp;
            ans++;
            
            if (isOriginal(a))
                break;
        }
        
        return ans % MOD;
    }
};