/*
Given an array arr[], find the smallest number x such that when x is processed sequentially with each element of the array (from index 0 to n-1), it never becomes negative, under the following conditions:

If x is greater than the current array element, x is increased by the difference between x and the array element.
If x is less than or equal to the current array element, x is decreased by the difference between the array element and x.
*/

#include<iostream>
#include <vector>
using namespace std;

// TC = O(n*k)
class Solution {
  public:
    int find(vector<int>& arr) {
        int i = 0;
        bool flag = false;
        
        while(!flag) {
            flag = true;
            int x = i;
            i++;
        
            for(int it : arr) {
                if(x > it)
                    x += x - it;
                else
                    x -= it - x;
        
                if(x < 0) {
                    flag = false;
                    break;
                }
            }
        }
        
        return i - 1;
    }
};


// TC = O(n)
class Solution {
  public:
    int find(vector<int>& arr) {
        int need = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            need = (need + arr[i] + 1) / 2;
        }
    
        return need;
    }
};