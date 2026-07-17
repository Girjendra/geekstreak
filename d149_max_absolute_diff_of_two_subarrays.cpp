/*
Given an array of integers arr[], find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
  public:
    vector<int> buildLeftMax(vector<int> &arr) {
        int n = arr.size();
    
        vector<int> leftMax(n);
    
        int curr = arr[0];
        int best = arr[0];
    
        leftMax[0] = best;
    
        for (int i = 1; i < n; i++) {
            curr = max(arr[i], curr + arr[i]);
    
            best = max(best, curr);
    
            leftMax[i] = best;
        }
    
        return leftMax;
    }
    
    vector<int> buildRightMax(vector<int> &arr) {
        int n = arr.size();
    
        vector<int> rightMax(n);
    
        int curr = arr[n - 1];
        int best = arr[n - 1];
    
        rightMax[n - 1] = best;
    
        for (int i = n - 2; i >= 0; i--) {
            curr = max(arr[i], curr + arr[i]);

            best = max(best, curr);
    
            rightMax[i] = best;
        }
    
        return rightMax;
    }

    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> leftMax = buildLeftMax(arr);
        vector<int> rightMax = buildRightMax(arr);
    
        vector<int> inverted(arr);
    
        for (int &x : inverted)
            x = -x;
    
        vector<int> leftMin = buildLeftMax(inverted);
        vector<int> rightMin = buildRightMax(inverted);
    
        for (int &x : leftMin)
            x = -x;
    
        for (int &x : rightMin)
            x = -x;
    
        int res = INT_MIN;
    
        for (int i = 0; i < n - 1; i++) {
            int option1 = abs(leftMax[i] - rightMin[i + 1]);
            int option2 = abs(leftMin[i] - rightMax[i + 1]);
    
            res = max(res, max(option1, option2));
        }
    
        return res;
        
    }
};