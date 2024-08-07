/*
Link: https://leetcode.com/problems/top-k-frequent-elements/description/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(auto it: nums){
            m[it]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>>pq;
        for(auto it: m){
            pq.push({it.second, it.first});
        }
        vector<int>ans;
        while(!pq.empty() && k > 0){
            k--;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Follow up in O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(auto it: nums){
            m[it]++;
        }
        vector<vector<int>>count(nums.size()+1, vector<int>());
        for(auto it: m){
            count[it.second].push_back(it.first);
        }
        vector<int>ans;
        int i = count.size()-1;
        while(i >= 0 && k > 0){
            if(count[i].size() > 0){
                k -= count[i].size();
                ans.insert(ans.end(), count[i].begin(), count[i].end());
            }
            i--;
        }
        return ans;
    }
};