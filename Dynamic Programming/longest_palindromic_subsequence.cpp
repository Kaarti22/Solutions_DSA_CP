/*
Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    #define vi vector<int>
    #define vvi vector<vector<int>>
    #define rep(i,a,b) for(int i=a; i<b; i++)

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vvi dp(n+1, vi(n+1));
        rep(i,0,n+1){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        rep(i,1,n+1){
            rep(j,1,n+1){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
};