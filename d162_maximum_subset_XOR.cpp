/*
Given an array arr[], choose any subset of elements (possibly all elements) such that the XOR of the chosen elements is maximized.
*/
#include<iostream>
#include <vector>
using namespace std;

// TC = O(2^n) and SC = O(n)
class Solution {
  public:
    void solve(int i, int cur, int& ans, vector<int>& arr) {
        if(i >= arr.size())
            return ;
            
        solve(i+1, cur, ans, arr);
        
        ans = max(ans, cur^arr[i]);
        solve(i+1, cur^arr[i], ans, arr);
    }
    
    int maxSubsetXOR(vector<int> &arr) {
        int ans = 0;
        solve(0, 0, ans, arr);
        
        return ans;
    }
};

// TC = O(n*32) and SC = O(1)
class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int index = 0;
        for (int bit = 31; bit >= 0 && index < n; bit--) {
            int maxIndex = index;
            
            for (int i = index; i < n; i++)
                if ((arr[i] & (1 << bit)) && arr[i] > arr[maxIndex])
                    maxIndex = i;
    
            if ((arr[maxIndex] & (1 << bit)) == 0)
                continue;
            
            swap(arr[index], arr[maxIndex]);

            for (int i = 0; i < n; i++)
                if (i != index && (arr[i] & (1 << bit)))
                    arr[i] ^= arr[index];
    
            index++;
        }
    
        int ans = 0;
        for (int num : arr)
            ans ^= num;
    
        return ans;
    }
};