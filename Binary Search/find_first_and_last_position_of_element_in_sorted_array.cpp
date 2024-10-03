/*
Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int index(vector<int>& nums, int target, bool f){
        int n = nums.size();
        int low = 0, high = n - 1;
        int ind = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else {
                ind = mid;
                /*
                    f = 1 -> find leftMost index
                    f = 0 -> find rightMost index
                */
                if(f) high = mid - 1;
                else low = mid + 1;
            }
        }
        return ind;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = index(nums, target, 1);
        int right = index(nums, target, 0);
        return {left, right};
    }
};