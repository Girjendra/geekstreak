/*
Given root of a binary tree in which all node values are distinct, count pairs of nodes that violate any of the
following Binary Search Tree (BST) properties.
All values in the left subtree are strictly smaller.
All values in the right subtree are strictly greater.
Examples:

Input: root[] = [10, 50, 40, N, N, 20, 30]
2056958715
Output: 5
Explanation: Pairs violating BST property are:-
(10, 50), 10 should be greater than its left child value.
(40, 30), 40 should be less than its right child value.
(50, 20), (50, 30) and (50, 40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.

Input: root[] = [80, 40, 30, 70, N, 60, 50]
Output: 10
Explanation: There are total 10 pairs (80, 30), (80, 60), (80, 50), (30, 60), (40, 70), (40, 30), (40, 50), (70, 30), (70, 60), (70, 50) which violate the BST properties.

Constraints:
1 ≤ size of binary tree ≤ 5*104
1 ≤ node.data ≤ 109
All node values are distinct.
*/
#include<iostream>
#include <vector>
using namespace std;








// BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


// TC : O(n^2) | SC : O(n)
class Solution {
    public:
        void inorder(Node* root, vector<int>& arr) {
            if (root == nullptr)
                return;
        
            inorder(root->left, arr);
            arr.push_back(root->data);
            inorder(root->right, arr);
        }
        
        int pairsViolatingBST(Node *root) {
            vector<int> arr;
            inorder(root, arr);

            int count = 0;
            for (int i = 0; i < arr.size(); i++)
                for (int j = i + 1; j < arr.size(); j++)
                    if (arr[i] > arr[j])
                        count++;

            return count;
        }
};








// TC : O(n log n) | SC : O(n)
class Solution {
    public:
        void inorder(Node* root, vector<int>& arr) {
            if (root == nullptr)
                return;
        
            inorder(root->left, arr);
            arr.push_back(root->data);
            inorder(root->right, arr);
        }
        
        long long mergeSort(vector<int>& arr, int low, int high) {
            if (low >= high)
                return 0;
        
            int mid = low + (high - low) / 2;
            long long count = mergeSort(arr, low, mid);
            count += mergeSort(arr, mid + 1, high);
        
            vector<int> temp;
            int i = low, j = mid + 1;

            while (i <= mid && j <= high) {
                if (arr[i] < arr[j]) {
                    temp.push_back(arr[i++]);
                }
                else {
                    count += mid - i + 1;
                    temp.push_back(arr[j++]);
                }
            }

            while (i <= mid)
                temp.push_back(arr[i++]);
            while (j <= high)
                temp.push_back(arr[j++]);

            for (int k = low; k <= high; k++)
                arr[k] = temp[k - low];
        
            return count;
        }
        
        int pairsViolatingBST(Node *root) {
            vector<int> arr;
            inorder(root, arr);
            
            return (int)mergeSort(arr, 0, arr.size() - 1);
        }
};