/*
Given three stacks s1, s2, and s3, represented by arrays where the first element of each array represents the top of the
corresponding stack.
Find the maximum possible equal sum(sum of all elements) of all three stacks by removing zero or more elements from the
top of each stack.
If it is not possible to make the sum of all three stacks equal, return 0.

Examples:
Input: s1 = [3, 2, 1, 1, 1], s2 = [4, 3, 2], s3 = [2, 5, 4, 1]
Output: 5
Explanation: Remove 3 from s1, 4 from s2, and 2, 5 from s3. The remaining sums of all three stacks are equal to 5.
pop

Input: s1 = [4,7], s2 = [10], s3 = [1,2,3]
Output: 0
Explanation: It is not possible to make the sums of all three stacks equal by removing elements from their tops.

Constraints:
1 ≤ s1.size(), s2.size(), s3.size() ≤ 5 * 10^5
1 ≤ s1[i], s2[i], s3[i] ≤ 10^3
*/
#include<iostream>
#include <vector>
using namespace std;








// TC : O(n1 + n2 + n3) SC : O(1)
class Solution {
public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int i = n1, j = n2, k = n3;
        
        int cs1 = 0, cs2 = 0, cs3 = 0;
        int ans = 0;
        
        while(i >= 0 && j >= 0 && k >= 0) {
            if(cs1 == cs2 && cs2 == cs3)
                ans = cs1;
                
            if(cs1 <= cs2 && cs1 <= cs3)
                cs1 += s1[--i];
            else if(cs2 <= cs1 && cs2 <= cs3)
                cs2 += s2[--j];
            else
                cs3 += s3[--k];
        }
        
        return ans;
    }
};