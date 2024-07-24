/*
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int>m;
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        while(j < n){
            m[s[j]]++;
            if(m[s[j]] > 1){
                while(m[s[j]] > 1){
                    m[s[i]]--;
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};