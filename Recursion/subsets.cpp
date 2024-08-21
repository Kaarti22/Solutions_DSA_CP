/*
Link: https://leetcode.com/problems/subsets/description/

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generateSubsets(int ind, int n, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        if(ind == n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        generateSubsets(ind + 1, n, nums, v, ans);
        v.pop_back();
        generateSubsets(ind + 1, n, nums, v, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        generateSubsets(0, nums.size(), nums, v, ans);
        return ans;
    }
};