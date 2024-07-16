/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            // odd length palindromes
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > ans.size()){
                    ans = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
            // even length palindromes
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > ans.size()){
                    ans = s.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};