/*
Link: https://leetcode.com/problems/find-unique-binary-string/description/

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void next(string& curr){
        int n = curr.size();
        int ind = -1;
        for(int i=n-1; i>=0; i--){
            if(curr[i] == '0'){
                ind = i;
                break;
            }
        }
        curr[ind] = '1';
        for(int i=ind+1; i<n; i++){
            curr[i] = '0';
        }
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>s(nums.begin(), nums.end());
        int n = nums.size();
        string curr = "";
        for(int i=0; i<n; i++) curr += "0";
        while(s.find(curr) != s.end()){
            next(curr);
        }
        return curr;
    }
};