/*
Given a bag of size w kg and you are provided costs of packets different weights of oranges in array cost[], find the minimum total cost to buy exactly w kg oranges

The cost of 1 kg orange is present at index 0 and in general arr[i] has cost of (i+1) kg orange.
cost[i] = -1 means that 'i+1' kg packet of orange is unavailable.
If it is not possible to buy exactly w kg oranges then return -1. It may be assumed that there is an infinite supply of all available packet types.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int solve(int w, vector<pair<int,int>>& packets, vector<int>& dp) {
        if(w == 0)
            return 0;

        if(dp[w] != -1)
            return dp[w];

        int ans = 1e9;

        for(auto p : packets) {
            int wt = p.first;
            int cost = p.second;

            if(w >= wt) {
                int temp = solve(w - wt, packets, dp);

                if(temp != 1e9)
                    ans = min(ans, cost + temp);
            }
        }

        return dp[w] = ans;
    }

    int minimumCost(vector<int>& cost, int w) {
        vector<pair<int,int>> packets;

        for(int i = 0; i < cost.size(); i++) {
            if(cost[i] != -1)
                packets.push_back({i + 1, cost[i]});
        }

        vector<int> dp(w + 1, -1);

        int ans = solve(w, packets, dp);

        return (ans == 1e9 ? -1 : ans);
    }
};