/*
Geek is creating a social networking site called Geeksbook with n users numbered from 1 to n. Each user i (2 ≤ i ≤ n) has exactly one friend, and that friend must have a smaller user number than i. User 1 has no friend. The friends of users 2 to n are given in an array arr[] of size n - 1, where:

arr[0] is the friend of user 2.
arr[1] is the friend of user 3.
...
arr[i - 2] is the friend of user i.
The relationship is one-way. A user can reach another user by repeatedly following their friend's link. For every user i from 2 to n, find all users j (1 ≤ j < i) that can be reached from i. For every reachable pair (i, j), create an array [i, j, k] where:

i is the starting user.
j is the reachable user.
k is the number of links that must be followed to reach j from i.
The result should contain these arrays in the following order:

Process users i from 2 to n.
For each user i, consider users j from 1 to i - 1 in increasing order.
Include [i, j, k] only if j is reachable from i.

Return a 2D array containing information about all reachable pairs.

Examples:
Input: arr[] = [1, 2]
Output: [[2, 1, 1], [3, 1, 2], [3, 2, 1]]
Explanation: The links are 2 → 1 and 3 → 2. User 2 can reach user 1 in 1 link. User 3 can reach user 1 in 2 links. User 3 can reach user 2 in 1 link.

Input: arr[] = [1, 1]
Output: [[2, 1, 1], [3, 1, 1]]
Explanation: The links are 2 → 1 and 3 → 1. User 2 can reach user 1 in 1 link. User 3 can reach user 1 in 1 link.

Constraints:
2 ≤ arr.size() ≤ 500
1 ≤ arr[i] ≤ 500
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;






// TC : O(n^2 log n), SC: O(n^2)
class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int, int>>> adj(n + 2);
        adj[2].push_back({1, 1});
        
        for(int i = 3; i <= n + 1; i++) {
            int fri = arr[i - 2];
            adj[i].push_back({fri, 1});
            
            for(auto it : adj[fri]) {
                int subFri = it.first;
                int link = it.second;
                
                adj[i].push_back({subFri, link + 1});
            }
        }

        vector<vector<int>> ans;
        for(int i = 2; i <= n + 1; i++) {
            for(auto it : adj[i]) {
                ans.push_back({i, it.first, it.second});
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};