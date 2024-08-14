/*
Link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<= str1.size(), str2.size()<=1000
Both strings may contain upper and lower case alphabets.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int dp[n+1][m+1];
        for(int i=0; i<n+1; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<m+1; j++){
            dp[0][j] = 0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        int maxi = 0;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};