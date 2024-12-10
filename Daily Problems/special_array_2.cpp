/*
Link: https://leetcode.com/problems/special-array-ii/description/

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

 

Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    pair<int, int>ub(int st, vector<pair<int, int>>& v){
        int n = v.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(v[mid].first > st) high = mid - 1;
            else low = mid + 1;
        }
        if(low >= n) return {-1, -1};
        return v[low];
    }

public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<pair<int, int>>v;
        for(int i=0; i<n-1; i++){
            if((nums[i] & 1) == (nums[i + 1] & 1)){
                v.push_back({i, i + 1});
                v.push_back({i + 1, i});
            }
        }
        vector<bool>ans;
        for(auto it: queries){
            int st = it[0], end = it[1];
            pair<int, int> p = ub(st, v);
            if((p.first == -1) || (p.first >= end && p.second >= end)){
                ans.push_back(true);
                continue;
            }
            ans.push_back(false);
        }
        return ans;
    }
};