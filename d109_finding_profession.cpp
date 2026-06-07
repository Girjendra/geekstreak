/*
Consider a special family of Engineers and Doctors with following rules :

Everybody has two children.
First child of an Engineer is an Engineer and second child is a Doctor.
First child of an Doctor is Doctor and second child is an Engineer.
All generations of Doctors and Engineers start with Engineer.

The first few levels of the family tree are shown below :
Given level and position (pos) of a person in above ancestor tree, find profession of the person.
*/
#include<iostream>
using namespace std;
class Solution {
public:
    string profession(int level, int pos) {
        long long p = pos - 1;
        
        int flips = 0;
        while (p > 0) {
            flips += (p & 1);
            p >>= 1;
        }
        
        if (flips % 2 == 0)
            return "Engineer";
        else
            return "Doctor";
    }
};