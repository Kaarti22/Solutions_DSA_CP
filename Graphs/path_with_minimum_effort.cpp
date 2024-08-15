/*
Link: https://leetcode.com/problems/path-with-minimum-effort/description/

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}});
        distance[0][0] = 0;
        while (!pq.empty()) {
            auto currEffort = pq.top().first;
            auto x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            if (x == n - 1 && y == m - 1) {
                return currEffort;
            }
            for (auto it: dir) {
                int newX = x + it[0], newY = y + it[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int newEffort = max(currEffort, abs(heights[newX][newY] - heights[x][y]));        
                    if (newEffort < distance[newX][newY]) {
                        distance[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});
                    }
                }
            }
        }
        return distance[n-1][m-1];
    }
};
