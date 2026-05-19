/*
Given two integers, start and end, along with an array of integers arr[]. In one operation, you can multiply
the current value by any element from arr[], and then take the result modulo 1000 to obtain a new value.
Find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
*/
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        int mod = 1000;
        vector<int> dist(mod, -1);
        queue<int> q;
    
        q.push(start);
        dist[start] = 0;
    
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
    
            if (curr == end) {
                return dist[curr];
            }
    
            for (int i = 0; i < arr.size(); i++) {
                int next = (curr * arr[i]) % mod;
    
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
    
        return -1;
    }
};