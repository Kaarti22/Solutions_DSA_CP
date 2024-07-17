/*
Link: https://leetcode.com/problems/repeated-string-match/

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = "";
        int n = b.size()/a.size();
        for(int i=0; i<n; i++){
            s += a;
        }
        if(s.find(b) != string::npos){
            return n;
        }
        string prefixPlusS = a + s;
        string suffixPlusS = s + a;
        if(prefixPlusS.find(b) != string::npos || suffixPlusS.find(b) != string::npos){
            return n + 1;
        }
        string prefixSSuffix = a + s + a;
        if(prefixSSuffix.find(b) != string::npos){
            return n + 2;
        }
        return -1;
    }
};