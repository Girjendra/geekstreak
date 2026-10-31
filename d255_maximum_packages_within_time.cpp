/*
A delivery agent has to deliver packages at locations arranged in a line. The number of packages at the ith location is given
by arr[i].
The agent can start at any location and can only visit consecutive locations.
Visiting each location takes 1 unit of time.
Given arr[] and totalTime, find the maximum number of packages the agent can deliver within totalTime.

Examples:
Input: arr[] = [2, 1, 3, 5, 0, 1, 4], totalTime = 3
Output: 9
Explanation: The agent can visit three consecutive locations. Starting from the second location, it delivers arr[1] + arr[2] + arr[3]
= 1 + 3 + 5 = 9 packages.

Input: arr[] = [1, 6, 2, 5, 3, 4], totalTime = 2
Output: 8
Explanation: The agent can visit two consecutive locations. Starting from the second location, it delivers arr[1] + arr[2]
= 6 + 2 = 8 packages. Starting from the fourth location gives arr[3] + arr[4] = 5 + 3 = 8 packages. Hence, the maximum is 8 packages.

Constraints:
1 ≤ arr.size(), totalTime ≤ 10^5
0 ≤ arr[i] ≤ 103
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;








// TC : O(n^2), SC: O(1)
class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int ans = 0;
        int n = arr.size();
        
        for(int i = 0; i <= n; i++) {
            int currentPackages = 0;
            for(int j = i; j < n && j < i + totalTime; j++)
                currentPackages += arr[j];
            
            ans = max(ans, currentPackages);
        }
        
        return ans;
    }
};








// TC : O(n), SC: O(1)
class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int ans = INT_MIN;
        
        int n = arr.size();
        int currentPackages  = 0;
        int i = 0;
        int j = 0;
        for(; i < n; i++) {
            if(i < totalTime) {
                currentPackages += arr[i];
            }
            else {
                ans = max(ans, currentPackages);
                currentPackages -= arr[j++];
                currentPackages += arr[i];
            }
        }
        
        ans = max(ans, currentPackages);
        return ans;
    }
};