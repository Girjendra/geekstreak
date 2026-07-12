/*
Given an integer array arr[], where arr[i] denotes the number of tickets available with the i-th ticket seller.

The price of each ticket is equal to the number of tickets remaining with that seller at the time of sale. 
A seller can sell at most one ticket at a time, and after each sale, the price of the next ticket from that seller decreases by 1.
All sellers are allowed to sell at most k tickets in total.
Find the maximum amount that can be earned by selling k tickets. Return the answer modulo 109+7.
*/
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        int mod = 1000000007;
        int n = arr.size();
        priority_queue<int> q;
    
        for (int i = 0; i < n; i++)
            q.push(arr[i]);
    
        int res = 0, x;
    
        while (k && !q.empty())
        {
            x = q.top();
            q.pop();
            res = (res + x) % mod;
            x--;
            k--;
            if (x)
                q.push(x);
        }
        
        return res;
    }
};