/*
Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>luckyRow(n);
        for(int i=0; i<n; i++){
            int mini = 1e9;
            for(int j=0; j<m; j++){
                mini = min(mini, matrix[i][j]);
            }
            luckyRow[i] = mini;
        }
        vector<int>luckyColumn(m);
        for(int j=0; j<m; j++){
            int maxi = -1e9;
            for(int i=0; i<n; i++){
                maxi = max(maxi, matrix[i][j]);
            }
            luckyColumn[j] = maxi;
        }
        vector<int>lucky;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(luckyRow[i] == matrix[i][j] && luckyColumn[j] == matrix[i][j]){
                    lucky.push_back(matrix[i][j]);
                }
            }
        }
        return lucky;
    }
};