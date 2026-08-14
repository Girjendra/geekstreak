/*
There are n children standing in a queue, each assigned a number arr[i]. The teacher writes s on a paper and gives it to the first child.

Each child writes the sum of all numbers already on the paper and arr[i], then passes it to the next child.

Return true if x can be formed by adding some of the numbers written on the paper: else return false.
*/
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC: O(2^n) where n is the number of elements in sums not arr's size
// SC: O(n) for the recursive call stack
class Solution {
  public:
    bool solve(int i, long long sum, int& x, vector<long long>& sums) {
        if(sum == x)
            return true;
            
        if(i == sums.size() || sum > x)
            return false;
            
        bool yes = solve(i + 1, sum + sums[i], x, sums);
        bool no = solve(i + 1, sum, x, sums);
        
        return (yes || no);
    }
    
    bool isPossible(vector<int>& arr, int s, int x) {
        int n = arr.size();
        vector<long long> sums;
        
        sums.push_back(s);
        long long ts = 0;
        for(int i = 0; i < n; i++) {
            long long cs = ts + s + arr[i];
            sums.push_back(cs);
            ts += cs;
            
            if(cs > x)
                break;
        }
        
        return solve(0, 0, x, sums);
    }
};




// TC : O(n * x) where n is the number of elements in sums not arr's size
// SC : O(n * x) for the recursive call stack and dp array
class Solution {
public:
    bool solve(int i, long long sum, int& x,
               vector<long long>& sums,
               unordered_map<long long, bool>& dp) {

        if(sum == x)
            return true;

        if(i == sums.size() || sum > x)
            return false;

        long long key = (sum << 6) | i;

        if(dp.count(key))
            return dp[key];

        bool yes = solve(i + 1, sum + sums[i], x, sums, dp);
        bool no = solve(i + 1, sum, x, sums, dp);

        return dp[key] = (yes || no);
    }

    bool isPossible(vector<int>& arr, int s, int x) {
        int n = arr.size();

        vector<long long> sums;

        sums.push_back(s);

        long long ts = 0;

        for(int i = 0; i < n; i++) {
            long long cs = ts + s + arr[i];

            if(cs > x)
                break;

            sums.push_back(cs);
            ts += cs;
        }

        unordered_map<long long, bool> dp;

        return solve(0, 0, x, sums, dp);
    }
};