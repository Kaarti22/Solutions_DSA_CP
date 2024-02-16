/*

Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(auto i: arr){
            m[i]++;
        }
        vector<pair<int,int>>v;
        for(auto i: m){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i].first <= k){
                k -= v[i].first;
            } else {
                for(int j=i; j<v.size(); j++){
                    ans++;
                }
                break;
            }
        }
        return ans;
    }
};