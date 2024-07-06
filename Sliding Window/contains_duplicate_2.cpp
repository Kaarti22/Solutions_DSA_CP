/*
Link: https://leetcode.com/problems/contains-duplicate-ii/description/

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>m;
        if(k < n){
            for(int i=0; i<=k; i++){
                m[nums[i]]++;
                if(m[nums[i]] == 2) return true;
            }
            int i=0, j=k;
            while(j < n-1){
                m[nums[i]]--;
                i++, j++;
                m[nums[j]]++;
                if(m[nums[j]] == 2) return true;
            }
            return false;
        }
        for(auto i: nums){
            m[i]++;
            if(m[i] == 2) return true;
        }
        return false;
    }
};