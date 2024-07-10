/*
Link: https://leetcode.com/problems/minimum-path-sum/description/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m];
        dp[0][0] = grid[0][0];
        for(int i=1; i<n; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1; i<m; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};