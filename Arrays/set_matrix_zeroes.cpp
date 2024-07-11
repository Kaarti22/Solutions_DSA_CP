/*
Link: https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for(int i=0; i<rows; i++){
            if(matrix[i][0] == 0){
                firstCol = true;
                break;
            }
        }
        for(int j=0; j<cols; j++){
            if(matrix[0][j] == 0){
                firstRow = true;
                break;
            }
        }
        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<rows; i++){
            if(matrix[i][0] == 0){
                for(int j=1; j<cols; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=1; j<cols; j++){
            if(matrix[0][j] == 0){
                for(int i=1; i<rows; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstRow){
            for(int j=0; j<cols; j++){
                matrix[0][j] = 0;
            }
        }
        if(firstCol){
            for(int i=0; i<rows; i++){
                matrix[i][0] = 0;
            }
        }
    }
};