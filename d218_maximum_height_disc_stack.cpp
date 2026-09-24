/*

*/
#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;



// TC : O(n^2) SC: O(n^2)
class Solution {
  public:
    int solve1(vector<vector<int>>& arr, int i, int pr, int ph) {
        if(i == arr.size())
            return 0;
    
        int take = INT_MIN;
    
        if(arr[i][0] < pr && arr[i][1] < ph) {
            int temp = solve1(arr, i+1, arr[i][0], arr[i][1]);
    
            if(temp != INT_MAX)
                take = temp + arr[i][1];
        }
    
        int skip = solve1(arr, i+1, pr, ph);
    
        return max(take, skip);
    }
    
    int solve2(vector<vector<int>>& arr, int i, int pr, int ph) {
        if(i == arr.size())
            return 0;
    
        int take = INT_MIN;
    
        if(arr[i][0] < ph && arr[i][1] < pr) {
            int temp = solve2(arr, i+1, arr[i][1], arr[i][0]);
    
            if(temp != INT_MAX)
                take = temp + arr[i][0];
        }
    
        int skip = solve2(arr, i+1, pr, ph);
    
        return max(take, skip);
    }
    
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();
        
        vector<vector<int>> a1(n, vector<int>(2)), a2(n, vector<int>(2));
        
        for(int i = 0; i < n; i++) {
            a1[i][0] = r[i];
            a1[i][1] = h[i];
            
            a2[i][0] = h[i];
            a2[i][1] = r[i];
        }
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        
        reverse(a1.begin(), a1.end());
        reverse(a2.begin(), a2.end());
        
        return max(solve1(a1, 0, INT_MAX, INT_MAX), solve2(a2, 0, INT_MAX, INT_MAX));
    }
};





// TC : O(n^2) SC: O(n^2)
class Solution {
  public:
    int solve1(vector<vector<int>>& arr, int i, int prev, vector<vector<int>>& dp) {
        if(i == arr.size())
            return 0;
    
        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
            
        int take = INT_MIN;
    
        if(prev == -1 || arr[i][0] < arr[prev][0] && arr[i][1] < arr[prev][1]) {
            int temp = solve1(arr, i+1, i, dp);
    
            if(temp != INT_MAX)
                take = temp + arr[i][1];
        }
    
        int skip = solve1(arr, i+1, prev, dp);
    
        return dp[i][prev + 1] = max(take, skip);
    }
    
    int solve2(vector<vector<int>>& arr, int i, int prev, vector<vector<int>>& dp) {
        if(i == arr.size())
            return 0;
    
        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
            
        int take = INT_MIN;
    
        if(prev == -1 || arr[i][0] < arr[prev][0] && arr[i][1] < arr[prev][1]) {
            int temp = solve2(arr, i+1, i, dp);
    
            if(temp != INT_MAX)
                take = temp + arr[i][0];
        }
    
        int skip = solve2(arr, i+1, prev, dp);
    
        return dp[i][prev + 1] = max(take, skip);
    }
    
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();
        
        vector<vector<int>> a1(n, vector<int>(2)), a2(n, vector<int>(2));
        
        for(int i = 0; i < n; i++) {
            a1[i][0] = r[i];
            a1[i][1] = h[i];
            
            a2[i][0] = h[i];
            a2[i][1] = r[i];
        }
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        
        reverse(a1.begin(), a1.end());
        reverse(a2.begin(), a2.end());
        
        vector<vector<int>> dp1(n, vector<int>(n + 1, -1));
        vector<vector<int>> dp2(n, vector<int>(n + 1, -1));

        return max(
            solve1(a1, 0, -1, dp1),
            solve2(a2, 0, -1, dp2)
        );
    }
};




// TC : O(nlogn) SC: O(n)
class Solution {
public:
    int solve(vector<pair<int,int>>& a) {
        int n = a.size();
        vector<int> vals;

        for(auto &p : a)
            vals.push_back(p.second);

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x.first > y.first;
        });

        int m = vals.size();
        vector<int> bit(m + 1, 0);

        auto query = [&](int idx) {
            int ans = 0;

            while(idx > 0) {
                ans = max(ans, bit[idx]);
                idx -= idx & -idx;
            }

            return ans;
        };

        auto update = [&](int idx, int val) {
            while(idx <= m) {
                bit[idx] = max(bit[idx], val);
                idx += idx & -idx;
            }
        };

        int ans = 0;
        int i = 0;

        while(i < n) {

            int j = i;

            while(j < n && a[j].first == a[i].first)
                j++;

            vector<pair<int,int>> temp;

            for(int p = i; p < j; p++) {

                int height = a[p].second;

                int pos = lower_bound(
                    vals.begin(),
                    vals.end(),
                    height
                ) - vals.begin() + 1;

                int revPos = m - pos + 1;

                int best = query(revPos - 1);

                int cur = height + best;

                temp.push_back({revPos, cur});

                ans = max(ans, cur);
            }

            for(auto &[pos, val] : temp)
                update(pos, val);

            i = j;
        }

        return ans;
    }

    int maxStackHeight(vector<int> &r, vector<int> &h) {

        int n = r.size();

        vector<pair<int,int>> discs;

        for(int i = 0; i < n; i++)
            discs.push_back({r[i], h[i]});

        return solve(discs);
    }
};