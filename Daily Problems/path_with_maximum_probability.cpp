/*
Link: https://leetcode.com/problems/path-with-maximum-probability/description/

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>>adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int>vis(n, 0);
        vis[start_node] = 1;
        priority_queue<pair<double, int>, vector<pair<double, int>>>pq;
        for(auto it: adj[start_node]){
            double wt = it.second;
            int adjNode = it.first;
            pq.push({wt, adjNode});
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double currWeight = it.first;
            int currNode = it.second;
            if(currNode == end_node){
                return currWeight;
            }
            vis[currNode] = 1;
            for(auto it: adj[currNode]){
                int adjNode = it.first;
                double wt = it.second;
                if(!vis[adjNode]){
                    double newWeight = currWeight * wt;
                    pq.push({newWeight, adjNode});
                }
            }
        }
        return 0;
    }
};