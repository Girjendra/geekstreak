/*
Given an array of negative and non-negative integers. You need to make the array beautiful.

An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or
positive. You can do the following operation any number of times until the array becomes beautiful.
If two adjacent are different i.e. one of them is negative and other is positive, remove them. 
Return the beautiful array after performing the above operation.
An empty array is also a beautiful array.
There can be multiple beautiful output arrays. For consistencty with the test cases, scan the array
from left to right for removing two adjacent.
*/
#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;
        
        for(int it : arr) {
            if(st.empty())
                st.push(it);
            else {
                int top = st.top();
                if((top >= 0 && it >= 0) || (top < 0 && it < 0))
                    st.push(it);
                else
                    st.pop();
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};