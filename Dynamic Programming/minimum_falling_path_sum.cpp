/*
Link: https://leetcode.com/problems/minimum-falling-path-sum/description/

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>dp(n);
        for(int i=0; i<n; i++){
            dp[i] = matrix[0][i];
        }
        for(int i=1; i<n; i++){
            vector<int>temp(n);
            for(int j=0; j<n; j++){
                if(j-1 >= 0){
                    if(j+1 < n){
                        temp[j] = min({dp[j-1], dp[j], dp[j+1]}) + matrix[i][j];
                    } else {
                        temp[j] = min(dp[j], dp[j-1]) + matrix[i][j];
                    }
                } else {
                    if(j+1 < n){
                        temp[j] = min(dp[j], dp[j+1]) + matrix[i][j];
                    } else {
                        temp[j] = dp[j] + matrix[i][j];
                    }
                }
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};