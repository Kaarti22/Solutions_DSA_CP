/*
Link: https://www.geeksforgeeks.org/problems/topological-sort/1

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

 

In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

 

Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2
*/

/*
Intuition: Insert all nodes with indegree 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int inDegree[V] = {0};
	    for(int i=0; i<V; i++){
	        for(auto it: adj[i]){
	            inDegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0; i<V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it: adj[node]){
	            inDegree[it]--;
	            if(inDegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
};