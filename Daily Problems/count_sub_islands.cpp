/*
Link: https://leetcode.com/problems/count-sub-islands/description/?envType=daily-question&envId=2024-08-28

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

 

Example 1:


Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:


Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
 

Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void makeZeroes(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m){
        for(auto d: dir){
            int x = i + d[0], y = j + d[1];
            if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && vis[x][y] == 0){
                vis[x][y] = 1;
                grid[x][y] = 0;
                makeZeroes(x, y, grid, vis, n, m);
            }
        }
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m){
        for(auto d: dir){
            int x = i + d[0], y = j + d[1];
            if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && vis[x][y] == 0){
                vis[x][y] = 1;
                dfs(x, y, grid, vis, n, m);
            }
        }
    }

public:
    vector<vector<int>>dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && grid1[i][j] == 0 && vis[i][j] == 0){
                    grid2[i][j] = 0;
                    vis[i][j] = 1;
                    makeZeroes(i, j, grid2, vis, n, m);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && vis[i][j] == 0){
                    ans++;
                    vis[i][j] = 1;
                    dfs(i, j, grid2, vis, n, m);
                }
            }
        }
        return ans;
    }
};