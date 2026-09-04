/*
Given an array arr[] representing the fruit values of trees arranged in a circle and an integer m, find the maximum total fruits the bird can collect by visiting at most m trees.

Bird can start from any tree and move to a neighboring tree.
The first and last trees are also considered neighbors.
The bird collects the fruit value of every tree it visits.
*/
#include<iostream>
#include <vector>
using namespace std;


// TC : O(n)
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int ans = 0;
        for(int i = 0; i < m; i++) {
            ans += arr[i];
        }
        
        int cs = ans;
        int i = 0, j = m, n = arr.size();
        while(j < n) {
            ans = max(ans, cs - arr[i] + arr[j]);
            cs = cs - arr[i] + arr[j];
            i++, j++;
        }
        
        i = n - m;
        j = n;
        while(i < n - 1) {
            ans = max(ans, cs - arr[i] + arr[j % n]);
            cs = cs - arr[i] + arr[j % n];
            i++, j++;
        }
        
        return ans;
    }
};



// TC : O(n)
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int ans = 0;
        for(int i = 0; i < m; i++) {
            ans += arr[i];
        }
        
        int cs = ans;
        int i = 0, j = m, n = arr.size();
        while(i < n) {
            ans = max(ans, cs - arr[i] + arr[j % n]);
            cs = cs - arr[i] + arr[j % n];
            i++, j++;
        }
        
        return ans;
    }
};