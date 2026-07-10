/*
Given a number n, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    int getCount(int n) {
        int ans = 0;
        int l = 1;
        int r = 1;
        int sum = 0;
        while(r < n) {
            if(sum < n) {
                sum += r;
                r++;
            }
            else if(sum > n){
                sum -= l;
                l++;
            }
            else {
                ans++;
                sum -= l;
                l++;
            }
        }
        
        return ans;
    }
};