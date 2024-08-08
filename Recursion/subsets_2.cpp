/*
Link: https://leetcode.com/problems/subsets-ii/description/

Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generateSubsets(vector<int>& nums, int n, int ind, set<vector<int>>& s, vector<int>& v){
        if(ind >= n) return;
        generateSubsets(nums, n, ind + 1, s, v);
        v.push_back(nums[ind]);
        s.insert(v);
        generateSubsets(nums, n, ind + 1, s, v);
        v.pop_back();
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        int n = nums.size();
        vector<int>v;
        s.insert(v);
        generateSubsets(nums, n, 0, s, v);
        vector<vector<int>>ans;
        for(auto it: s) ans.push_back(it);
        return ans;
    }
};