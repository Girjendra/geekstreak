/*
Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.
*/
#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
    Node* solve(Node* &head , int& mx) {
        if(!head->next) {
            mx = head->data;
            return head;
        }

        head->next = solve(head->next, mx);

        if(head->data < mx) {
            Node* temp = head->next;
            delete head;
            return temp;
        }

        mx = head->data;
        return head;
    }
    
  public:
    Node *compute(Node *head) {
        if(!head)
            return head;

        int mx = -1;
        return solve(head, mx);
    }
};