/*
Link: https://leetcode.com/problems/house-robber-ii/description/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int fun(vector<int>& nums, int ind, vector<int>& dp, int st){
        if(ind < st) return 0;
        if(ind == st) return dp[ind] = nums[st];
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(nums[ind] + fun(nums, ind-2, dp, st), fun(nums, ind-1, dp, st));
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        if(n == 1) return nums[0];
        int ans1 = fun(nums, n-1, dp, 1);
        for(int i=0; i<n; i++) dp[i] = -1;
        int ans2 = fun(nums, n-2, dp, 0);
        return max(ans1, ans2);
    }
};