/*
Link: https://leetcode.com/problems/sort-an-array/description/

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void heapify(vector<int>& nums, int n, int i){
        int maxInd = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if(l < n && nums[l] > nums[maxInd]){
            maxInd = l;
        }
        if(r < n && nums[r] > nums[maxInd]){
            maxInd = r;
        }
        if(maxInd != i){
            swap(nums[i], nums[maxInd]);
            heapify(nums, n, maxInd);
        }
    }

    void heapsort(vector<int>& nums){
        int n = nums.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(nums, n, i);
        }
        for(int i=n-1; i>0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
        return nums;
    }
};