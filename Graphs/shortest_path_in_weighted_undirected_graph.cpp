/*
Link: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Examples :

Input: n = 5, m= 6, edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1], [4,3,3], [3,5,1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
Input: n = 2, m= 1, edges = [[1,2,2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n)

Constraint:
2 <= n <= 106
0 <= m <= 106
0<= a, b <= n
1 <= w <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n+1, 1e9), parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        dist[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int distance = it.first;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(distance + edgeWeight < dist[adjNode]){
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        vector<int>path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        return path;
    }
};