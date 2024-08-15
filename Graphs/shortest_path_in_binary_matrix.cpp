/*
Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] != 0) return -1;
        vector<vector<int>>distance(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                distance[i][j] = INT_MAX;
            }
        }
        distance[0][0] = 1;
        queue<pair<int, pair<int, int>>>q;
        q.push({1, {0, 0}});
        while(!q.empty()){
            auto currDistance = q.front().first;
            auto x = q.front().second.first, y = q.front().second.second;
            q.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i == 0 && j == 0) continue;
                    int newX = x + i, newY = y + j;
                    if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0){
                        if(currDistance + 1 < distance[newX][newY]){
                            distance[newX][newY] = currDistance + 1;
                            q.push({distance[newX][newY], {newX, newY}});
                        }
                    }
                }
            }
        }
        if(distance[n-1][m-1] == INT_MAX) return -1;
        return distance[n-1][m-1];
    }
};