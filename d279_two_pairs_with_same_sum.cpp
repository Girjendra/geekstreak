/*
Given an array arr[] of positive integers, find four indices a, b, c, and d such that arr[a] + arr[b] = arr[c] + arr[d],
where a, b, c, d are all distinct indices.
If multiple such quadruplets exist, return the one that is lexicographically smallest when the indices are considered in
the order a, b, c, d.
If no such quadruplet exists, return {-1, -1, -1, -1}. 
Ensure a < b and c < d, and the pair (a, b) is lexicographically smaller than the pair (c, d).

Examples:
Input: arr[] = [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5]
Explanation: arr[0] + arr[2] = 3 + 7 = 10, arr[3] + arr[5] = 1 + 9 = 10. 
This is the lexicographically smallest such quadruplet of indices.

Input: arr[] = [1, 2, 3, 3]
Output: [-1, -1, -1, -1]
Explanation: No two distinct pairs of indices produce the same sum.

Constraints:
4 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 107
*/
#include<iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;







// TC : O(n^4), SC : O(1)
class Solution {
public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(4, INT_MAX);
        
        for(int a = 0; a < n; a++) {
            for(int b = a + 1; b < n; b++) {
                for(int c = 0; c < n; c++) {
                    for(int d = c + 1; d < n; d++) {
                        if (a > c || (a == c && b >= d))
                            continue;
                        
                        if (a == c || a == d || b == c || b == d)
                            continue;
                                                
                        if((arr[a] + arr[b]) == (arr[c] + arr[d])) {
                            return {a, b, c, d};
                        }
                    }
                }
            }
        }

        return {-1, -1, -1, -1};
    }
};








// TC : O(n^2 log n), SC : O(n^2)
class Solution {
public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<pair<int, int>>> mp;
    
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                mp[arr[i] + arr[j]].push_back({i, j});
        }
    
        for (auto it : mp)
            sort(it.second.begin(), it.second.end());
    
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                int sum = arr[a] + arr[b];
                auto it = mp.find(sum);
                if (it == mp.end())
                    continue;
    
                for (auto it2 : it->second) {
                    int c = it2.first;
                    int d = it2.second;
                    if (c == a || c == b || d == a || d == b)
                        continue;
    
                    if (a < c || (a == c && b < d))
                        return {a, b, c, d};
                }
            }
        }
    
        return {-1, -1, -1, -1};
    }
};









// TC : O(n^2), SC : O(n^2)
class Solution {
public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, pair<int, int>> mp;
        vector<int> res;
    
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];

                if (mp.find(sum) == mp.end()) {
                    mp[sum] = {i, j};
                    continue;
                }
    
                int a = mp[sum].first;
                int b = mp[sum].second;
    
                if (a == i || a == j || b == i || b == j)
                    continue;
    
                vector<int> cur = {a, b, i, j};
                if (res.empty() || cur < res)
                    res = cur;
            }
        }
    
        if (res.empty())
            return {-1, -1, -1, -1};
    
        return res;
    }
};