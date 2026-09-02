/*
A cafe has n computers. The customer events are represented by a string s of uppercase English letters, where each distinct letter appears exactly twice:

The first occurrence denotes the customer's arrival.
The second occurrence denotes the customer's departure.
A customer is assigned a computer only if one is available at the time of arrival, otherwise the customer is rejected and does not use a computer.

Return the number of customers who could not be assigned a computer upon arrival.
*/
#include<iostream>
#include <unordered_set>
using namespace std;



// TC : O(n), SC: O(n)
class Solution {
public:
    int solve(int n, string s) {
        unordered_set<char> active;
        unordered_set<char> rejected;

        int ans = 0;
        for(char ch : s) {
            if(rejected.count(ch))
                continue;

            if(active.count(ch)) {
                active.erase(ch);
                continue;
            }

            if(active.size() < n)
                active.insert(ch);
            else {
                rejected.insert(ch);
                ans++;
            }
        }

        return ans;
    }
};