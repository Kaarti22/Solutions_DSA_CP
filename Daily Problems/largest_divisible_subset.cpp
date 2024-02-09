/*

Link: https://leetcode.com/problems/largest-divisible-subset/description/

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        if(n == 0){
            return ans;
        }
        sort(nums.begin(), nums.end());
        int maxi = 1;
        vector<int>dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        int prev = -1;
        for(int i=n-1; i>=0; i--){
            if(dp[i] == maxi && (prev % nums[i] == 0 || prev == -1)){
                ans.push_back(nums[i]);
                maxi -= 1;
                prev = nums[i];
            }
        }
        return ans;
    }
};