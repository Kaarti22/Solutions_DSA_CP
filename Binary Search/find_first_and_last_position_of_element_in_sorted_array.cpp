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
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int index = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                index = mid;
                break;
            }
            if(nums[mid] < target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(index == -1) return {-1, -1};
        int leftIndex = index, rightIndex = index;
        while(leftIndex >= 0 && nums[leftIndex] == target){
            leftIndex--;
        }
        while(rightIndex < n && nums[rightIndex] == target){
            rightIndex++;
        }
        return {leftIndex + 1, rightIndex - 1};
    }
};