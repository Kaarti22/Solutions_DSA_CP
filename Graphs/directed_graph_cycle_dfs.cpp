/*
Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool dfs(int node, vector<int>adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis)){
                    return true;
                }
            } else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)){
                    return true;
                }
            }
        }
        return false;
    }
};