/*
Given an integer array arr[], count the number of positive integers k such that all elements of the array leave the same remainder when divided by k.

If there are infinitely many such values of k, return -1.

Constraints:
1 ≤ arr.size(), arr[i] ≤ 105
*/
#include<iostream>
#include <vector>
using namespace std;

#include <algorithm>
#include <cmath>
#include <numeric>

// TC : O(n * max(arr))
class Solution {
  public:
    bool isrem(int i, vector<int>& arr) {
        int rem = arr[0] % i;
        
        for(int it : arr)
            if(it % i != rem)
                return false;
                
        return true;
    }
    
    int sameMod(vector<int> &arr) {
        int n = arr.size();
        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());
        
        if(mini == maxi)
            return -1;
            
        int ans = 1;
        for(int i = 2; i <= maxi; i++) {
            if(isrem(i, arr))
                ans++;
        }

        return ans;
    }
};



// TC : O(n * log(max(arr)))
class Solution {
public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();

        int g = 0;

        for(int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }

        if(g == 0)
            return -1;

        int ans = 0;

        for(int i = 1; i <= g/2; i++) {
            if(g % i == 0)
                ans++;
        }

        return ans+1;
    }
};