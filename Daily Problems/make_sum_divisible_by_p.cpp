/*
Link: https://leetcode.com/problems/make-sum-divisible-by-p/description/

Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= p <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(auto it: nums) sum += (1ll * it);
        int rem = sum % p;
        if(rem == 0) return 0;
        int ans = n;
        int currSum = 0;
        unordered_map<int, int>m;
        m[0] = -1;
        for(int i=0; i<n; i++){
            currSum = (currSum + nums[i]) % p;
            int prefix = (currSum - rem + p) % p;
            if(m.find(prefix) != m.end()){
                int len = i - m[prefix];
                ans = min(ans, len);
            }
            m[currSum] = i;
        }
        if(ans == n) return -1;
        return ans;
    }
};