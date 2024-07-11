/*
Link: https://leetcode.com/problems/pascals-triangle/description/

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1; i<numRows; i++){
            vector<int>curr = ans.back();
            int n = curr.size();
            if(n == 1){
                ans.push_back({1, 1});
                continue;
            }
            vector<int>next;
            next.push_back(curr[0]);
            for(int j=0; j<n-1; j++){
                next.push_back(curr[j] + curr[j+1]);
            }
            next.push_back(curr[n-1]);
            ans.push_back(next);
        }
        return ans;
    }
};