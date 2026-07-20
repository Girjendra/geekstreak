/*
Given an array of strings arr[ ], find the shortest prefix of each string that uniquely identifies it among all strings in the array. A prefix is unique if it is not a prefix of any other string in the array.
Note: No string in the given array is a prefix of another string.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
         vector<string> ans;
    
        for (int i = 0; i < arr.size(); i++) {
            string word = arr[i];
            bool found = false;
    
            for (int len = 1; len <= word.size(); len++) {
                string prefix = word.substr(0, len);
    
                bool unique = true;
    
                for (int j = 0; j < arr.size(); j++) {
                    if (i == j)
                        continue;
    
                    if (arr[j].size() >= len &&
                        arr[j].substr(0, len) == prefix) {
                        unique = false;
                        break;
                    }
                }
    
                if (unique) {
                    ans.push_back(prefix);
                    found = true;
                    break;
                }
            }
    
            if (!found)
                ans.push_back(word);
        }
    
        return ans;
    }
};





class Node {
private:
    vector<Node*> children;
    int freq;
    char ch;

public:
    Node(char x) {
        freq = 0;
        ch = x;
        children = vector<Node*>(26, nullptr);
    }

    void insert(string& word) {
        Node* curr = this;
        for(char c : word) {
            if(curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new Node(c);
            }
            curr = curr->children[c-'a'];
            curr->freq++;
        }
    }

    int findPrefix(string& word) {
        Node* curr = this;
        for(int i = 0; i < word.length(); i++) {
            curr = curr->children[word[i]-'a'];
            
            if(curr->freq == 1) {
                return i;
            }
        }
        return word.length() - 1;
    }
};

class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
         int n = arr.size();
        Node* root = new Node('*');
        
        for(int i=0; i<n; i++)
            root->insert(arr[i]);
        
        vector<string> result;
        
        for(int i=0; i<n; i++) {
            string word = arr[i];
            int endIndex = root->findPrefix(word);
            result.push_back(word.substr(0, endIndex + 1));
        }
        
        return result;
    }
};