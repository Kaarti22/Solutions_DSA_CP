/*
Link: https://leetcode.com/problems/network-delay-time/description/

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1, vector<pair<int, int>>());
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int>distance(n+1, 1e9);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currDistance = it.first;
            int node = it.second;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(currDistance + edgeWeight < distance[adjNode]){
                    distance[adjNode] = currDistance + edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        int minimumTime = 0;
        for(int i=1; i<=n; i++){
            if(distance[i] == 1e9) return -1;
            minimumTime = max(minimumTime, distance[i]);
        }
        return minimumTime;
    }
};