/*
Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Note : Modify the distances for every pair in-place.

Examples :

Input: matrix = [[0, 25],[-1, 0]]

Output: [[0, 25],[-1, 0]]

Explanation: The shortest distance between every pair is already given(if it exists).
Input: matrix = [[0, 1, 43],[1, 0, 6],[-1, -1, 0]]

Output: [[0, 1, 7],[1, 0, 6],[-1, -1, 0]]

Explanation: We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 43.
Expected Time Complexity: O(n3)
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 100
-1 <= matrix[ i ][ j ] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
	        }
	    }
	    for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    for(int i=0; i<n; i++){
	        if(matrix[i][i] < 0){
	            cout<<"Negative cycle"<<endl;
	        }
	    }
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};