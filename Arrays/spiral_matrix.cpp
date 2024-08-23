/*
Link: https://leetcode.com/problems/spiral-matrix/description/

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>ans;
        int left = 0, right = m, top = 0, bottom = n;
        while(left < right && top < bottom){
            for(int i=left; i<right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<bottom; i++){
                ans.push_back(matrix[i][right-1]);
            }
            right--;
            if(!(left < right && top < bottom)){
                break;
            }
            for(int i=right-1; i>=left; i--){
                ans.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for(int i=bottom-1; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};