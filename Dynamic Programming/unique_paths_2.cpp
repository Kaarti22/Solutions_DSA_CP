/*
Link: https://leetcode.com/problems/unique-paths-ii/description/

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0] == 1){
                for(int i1 = i; i1 < m; i1++){
                    dp[i1][0] = 0;
                }
                break;
            }
            dp[i][0] = 1;
        }
        for(int j=0; j<n; j++){
            if(obstacleGrid[0][j] == 1){
                for(int j1 = j; j1 < n; j1++){
                    dp[0][j1] = 0;
                }
                break;
            }
            dp[0][j] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(obstacleGrid[i-1][j] == 1){
                    if(obstacleGrid[i][j-1] == 1){
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                } else {
                    if(obstacleGrid[i][j-1] == 1){
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};