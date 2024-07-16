/*
Link: https://leetcode.com/problems/longest-common-prefix/description/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        int ind = 0;
        char prev = strs[0][0];
        for(int i=0; i<n; i++){
            int size = strs[i].size();
            if(ind >= size) break;
            if(strs[i][ind] != prev) break;
            if(i == n-1){
                ans.push_back(prev);
                ind++;
                i = 0;
                if(ind < strs[0].size()) prev = strs[0][ind];
                else break;
            }
        }
        return ans;
    }
};