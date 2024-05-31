/*

Link: https://leetcode.com/problems/rotting-oranges/description/

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        queue<pair<int,int>>temp;
        while(!q.empty()){
            queue<pair<int,int>>t = q;
            bool f = 0;
            while(!t.empty()){
                pair<int,int>p = t.front();
                t.pop();
                vis[p.first][p.second] = 1;
                for(auto d: dir){
                    int x = p.first + d[0];
                    int y = p.second + d[1];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                        if(vis[x][y] == 0){
                            vis[x][y] = 1;
                            grid[x][y] = 2;
                            temp.push({x, y});
                            f = 1;
                        }
                    }
                }
            }
            if(f){
                ans++;
                f = 0;
            } else {
                break;
            }
            q = temp;
            queue<pair<int,int>>e;
            temp = e;
        }
        bool f = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    f = 1;
                    break;
                }
            }
        }
        if(f) ans = -1;
        return ans;
    }
};