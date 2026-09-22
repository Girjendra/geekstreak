/*
Given a lowercase string s and a dictionary d[] containing lowercase words, find the longest word in the dictionary that can be obtained by deleting some characters from s without changing the order of the remaining characters.

Note: If multiple words have the same maximum length, return the lexicographically smallest one. If no valid word exists, return an empty string.
*/
#include<iostream>
#include <vector>
using namespace std;



// TC : O(n * m)
class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        string ans = "";
        for(string word : d) {

            int i = 0;
            int j = 0;

            while(i < s.size() && j < word.size()) {
                if(s[i] == word[j])
                    j++;

                i++;
            }

            if(j == word.size()) {
                if(word.size() > ans.size())
                    ans = word;
                else if(word.size() == ans.size() && word < ans)
                    ans = word;
            }
        }

        return ans;
    }
};




// TC : O(n + m)
class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        int n = s.size();
        vector<vector<int>> next(n + 1, vector<int>(26, -1));

        for(int i = n - 1; i >= 0; i--) {
            next[i] = next[i + 1];
            next[i][s[i] - 'a'] = i;
        }

        string ans = "";

        for(string &word : d) {
            int pos = 0;
            bool ok = true;

            for(char ch : word) {
                if(pos > n || next[pos][ch - 'a'] == -1) {
                    ok = false;
                    break;
                }

                pos = next[pos][ch - 'a'] + 1;
            }

            if(ok) {
                if(word.size() > ans.size() || (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};