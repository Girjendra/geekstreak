/*
Given a string s and a 2D array queries[][], where each query consists of two integers l and r, find the number of vowels in the substring
s[l....r] for each query. The substring includes both indices l and r.
Return an array containing the answers to all queries in the order they are given.
Examples:

Input: s = "geeksforgeeks", queries[][] = [[1, 3], [2, 4], [1, 9]]
Output: [2, 1, 4]
Explanation:
Query 1: "eek" has 2 vowels (e, e).
Query 2: "eks" has 1 vowel (e).
Query 3: "eeksforge" has 4 vowels (e, e, o, e).
Input: s = "helloworld", queries[][] = [[0, 4], [5, 9], [0, 9]]

Output: [2, 1, 3]
Explanation:
Query 1: "hello" has 2 vowels (e, o).
Query 2: "world" has 1 vowel (o).
Query 3: "helloworld" has 3 vowels (e, o, o).

Constraints:
1 ≤ s.size(), queries.size() ≤ 105
s consists only of lowercase English alphabets
queries[i].size() = 2
0 ≤ queries[i][0] ≤ queries[i][1] < s.size()
*/
#include<iostream>
#include <vector>
#include <set>
using namespace std;











// TC : O(n * q)  SC : O(1)
class Solution {
public:
    int findVowel(int st, int end, string& s) {
        int count = 0;
        for(int i = st; i <= end; i++)
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                count++;
                
        return count;
    }
    vector<int> countVowels(string &s, vector<vector<int>> &q) {
        vector<int> ans;
        
        for(auto it : q)
            ans.push_back(findVowel(it[0], it[1], s));
            
        return ans;
    }
};











// TC : O(n + q)  SC : O(n)
class Solution {
public:
    vector<int> countVowels(string &s, vector<vector<int>> &q) {
        vector<int> ans;
        vector<int> pre(s.size() + 1, 0);
        set<int> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        if(vowels.find(s[0]) != vowels.end())
            pre[1]++;
            
        for(int i = 1; i < s.size(); i++) {
            pre[i + 1] = pre[i];
            if(vowels.find(s[i]) != vowels.end())
                pre[i + 1]++;
        }

        for(auto it : q) {
            int count = pre[it[1] + 1] - pre[it[0]];
            ans.push_back(count);
        }
            
        return ans;
    }
};