/*
Given an integer array arr[]. In one operation, you can choose an index and increment its value by 1.
Find the maximum possible frequency of any element after performing at most k operations.

Examples:
Input: arr[] = [2, 2, 4], k = 4
Output: 3
Explanation: Apply two increment operations on index 0 and two operations on index 1 to make arr[]= [4, 4, 4]. Frequency of 4 is 3.

Input: arr[] = [7, 7, 7, 7], k = 5
Output: 4
Explanation: The frequency of 7 is already 4, so no operations are needed.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
0 ≤ k ≤ 105
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;






// TC : O(n^2) SC : O(1)
class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        int ans = 1;
        for(int i = 0; i < arr.size(); i++) {
            long long inc = 0;
            int fre = 1;
            
            for(int j = i - 1; j >= 0; j--) {
                inc += arr[i] - arr[j];
                
                if(inc > k)
                    break;
                    
                fre++;
                ans = max(ans, fre);

            }
        }
        
        return ans;
    }
};






// TC : O(nlogn) SC : O(n)
class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
    
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
    
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + arr[i];
    
        int res = 1;
        for (int right = 0; right < n; ++right) {
            int low = 0;
            int high = right;
    
            while (low < high) {
                int mid = low + (high - low) / 2;
                long long sum = prefix[right + 1] - prefix[mid];
                long long required = 1LL * arr[right] * (right - mid + 1) - sum;
    
                if (required <= k)
                    high = mid;
                else
                    low = mid + 1;
            }
    
            res = max(res, right - low + 1);
        }

        return res;
    }
};






// TC : O(nlogn) SC : O(1)
class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
    
        int res = 0;
        int winsum = 0;
        int left = 0;
        
        for (int right = 0; right < arr.size(); ++right) {
            winsum += arr[right];
            
            while (arr[right] * (right - left + 1) - winsum > k) {
                winsum -= arr[left];
                left++;
            }
    
            res = max(res, right - left + 1);
        }

        return res;
    }
};