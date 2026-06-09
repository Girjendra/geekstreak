/*
Given an integer k representing the number of people to be seated and an array seats[], where 0 denotes an empty seat and 1 denotes an occupied seat.

Determine whether it is possible to seat all k people such that no two occupied seats are adjacent (including newly seated people).
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        int n = seats.size();
        
        for (int i = 1; i < n; i++) {
            if (seats[i] == seats[i - 1] && seats[i - 1] == 1)
                return false;
        }
        
        for(int i = 0; i < n; i++) {
             if (seats[i] == 0) {
                bool leftEmpty = (i == 0 || seats[i - 1] == 0);
                bool rightEmpty = (i == n - 1 || seats[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    seats[i] = 1;
                    k--;
                    if (k == 0)
                        return true;
                }
             }
        }
        
        return k <= 0;
    }
};