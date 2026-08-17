/*
Given an integer n such that there is n × n Snakes and Ladders board with cells numbered from 1 to n*n, find the minimum number of dice throws required to reach cell n*n starting from cell 1. Given two arrays of even lengths:

lad[], where each pair (lad[2*i], lad[2*i + 1]) represents the start and end of a ladder.
sn[], where each pair (sn[2*i], sn[2*i + 1]) represents the start and end of a snake.
If you land on the start cell of a snake or ladder, you must immediately move to its corresponding end cell.

You have complete control over the outcome of each dice throw i.e., in a single move,  you can move forward by any number of cells from 1 to 6. 

If it is impossible to reach cell n*n, return -1.
*/
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        vector<int> moves(n * n + 1, -1);
        vector<bool> vis(n * n + 1, false);

        for (int i = 0; i < (int)lad.size(); i += 2)
            moves[lad[i]] = lad[i + 1];

        for (int i = 0; i < (int)sn.size(); i += 2)
            moves[sn[i]] = sn[i + 1];

        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;

        pair<int, int> cur;

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            int pos = cur.first;
            int dist = cur.second;

            if (pos == n * n)
                return dist;

            for (int nxt = pos + 1; nxt <= pos + 6 && nxt <= n * n; nxt++) {
                if (!vis[nxt]) {
                    vis[nxt] = true;

                    int dest = (moves[nxt] == -1) ? nxt : moves[nxt];
                    q.push({dest, dist + 1});
                }
            }
        }

        return -1;
    }
};