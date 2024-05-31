/*

Link: https://leetcode.com/problems/01-matrix/description/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<vector<int>>zeroes;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    zeroes.push({i, j});
                }
            }
        }
        vector<vector<int>>ans(n, vector<int>(m, 0));
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int dist = 0;
        while(!zeroes.empty()){
            dist++;
            queue<vector<int>>q = zeroes;
            queue<vector<int>>temp;
            while(!q.empty()){
                int row = q.front()[0], col = q.front()[1];
                q.pop();
                vis[row][col] = 1;
                for(auto d: dir){
                    int x = row + d[0], y = col + d[1];
                    if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1){
                        if(vis[x][y] == 0){
                            vis[x][y] = 1;
                            ans[x][y] = dist;
                            temp.push({x, y});
                        }
                    }
                }
            }
            zeroes = temp;
            queue<vector<int>>e;
            temp = e;
        }
        return ans;
    }
};