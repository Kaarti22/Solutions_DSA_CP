/*
Link: https://leetcode.com/problems/number-of-provinces/description/

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<int>& vis, int V, int n){
        queue<int>q;
        q.push(V);
        vis[V] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j=0; j<n; j++){
                if(adj[node-1][j] == 1){
                    if(vis[j+1] == 0){
                        vis[j+1] = 1;
                        q.push(j+1);
                    }
                }
            } 
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int>vis(n+1, 0);
        for(int i=1; i<=n; i++){
            if(vis[i] == 0){
                bfs(isConnected, vis, i, n);
                ans++;
            }
        }
        return ans;
    }
};