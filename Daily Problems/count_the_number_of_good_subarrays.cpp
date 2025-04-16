/*
Link: https://leetcode.com/problems/count-the-number-of-good-subarrays/description/?envType=daily-question&envId=2025-04-16

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.
Example 2:

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int, int>m;
        int c = 0;
        int j = -1;
        for(int i=0; i<n; i++){
            while(c < k && j + 1 < n){
                j++;
                c += m[nums[j]];
                m[nums[j]]++;
            }
            if(c >= k) ans += n - j;
            m[nums[i]]--;
            c -= m[nums[i]];
        }
        return ans;
    }
};