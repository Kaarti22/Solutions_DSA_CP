/*
Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            if(low == high) return nums[low];
            int mid = low + (high - low)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            } else if(nums[mid] == nums[mid-1]){
                if((mid - 2 - low + 1) & 1) {
                    high = mid - 2;
                } else {
                    low = mid + 1;
                }
            } else {
                if((mid - 1 - low + 1) & 1) {
                    high = mid - 1;
                } else {
                    low = mid + 2;
                }
            }
        }
        return nums[low];
    }
};