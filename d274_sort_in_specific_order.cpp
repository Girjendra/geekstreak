/*
Given an array arr[] of non-negative integers. Your need to sort them so that
The first part of the array contains odd numbers sorted in descending order.
The rest of the portion contains even numbers sorted in ascending order.

Examples:
Input: arr[] = [1, 2, 3, 5, 4, 7, 10]
Output: [7, 5, 3, 1, 2, 4, 10]
Explanation: 7, 5, 3, 1 are odd numbers in descending order and 2, 4, 10 are even numbers in ascending order.

Input: arr[] = [0, 4, 5, 3, 7, 2, 1]
Output: [7, 5, 3, 1, 0, 2, 4]
Explanation: 7, 5, 3, 1 are odd numbers in descending order and 0, 2, 4 are even numbers in ascending order.

Constraints:
1 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^9
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;








// TC : O(nlogn) SC: O(n)
class Solution {
public:
    void sortIt(vector<int>& arr) {
        int n = arr.size();
        vector<int> odd, even;
        for(int it : arr) {
            if(it % 2)
                odd.push_back(it);
            else
                even.push_back(it);
        }
        
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        
        int i = 0;
        for(int it : odd)
            arr[i++] = it;
        
        for(int it : even)
            arr[i++] = it;
    }
};










// TC : O(nlogn) SC: O(1); my approach
class Solution {
public:
    void sortIt(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while(true) {
            while(i < j && arr[i] % 2 == 1) i++;
            while(i < j && arr[j] % 2 == 0) j--;
            
            if(i < j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
            else
                break;
        }
        
        int temp = 0;
        while(temp < n && arr[temp] % 2 == 1)
            temp++;
        
        sort(arr.begin(), arr.begin() + temp, greater<int>());
        sort(arr.begin() + temp, arr.end());
    }
};








// TC : O(nlogn) SC: O(1)
class Solution {
public:
    void sortIt(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 == 1)
                swap(arr[i], arr[left++]);
        }
        
        sort(arr.begin(), arr.begin() + left, greater<int>());
        sort(arr.begin() + left, arr.end());
    }
};








// TC : O(nlogn) SC: O(1)
class Solution {
public:
    void sortIt(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 == 1)
                arr[i] *= -1;
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0)
                arr[i] *= -1;
        }
    }
};








// TC : O(nlogn) SC: O(1)
class Solution {
public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int& a, int& b) {
            if(a % 2 == 0 && b % 2 == 0)
                return a < b;
            else if(a % 2 == 1 && b % 2 == 1)
                return a > b;
            else
                return a % 2 == 1;
        });
    }
};