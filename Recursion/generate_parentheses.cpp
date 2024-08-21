/*
Link: https://leetcode.com/problems/generate-parentheses/description/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generate(int remainingNumberOfOpenBrackets, int usedOpenBrackets, vector<string>& ans, string& s){
        if(remainingNumberOfOpenBrackets == 0){
            if(usedOpenBrackets == 0){
                ans.push_back(s);
                return;
            }
            s.push_back(')');
            generate(remainingNumberOfOpenBrackets, usedOpenBrackets - 1, ans, s);
            s.pop_back();
        } else {
            s.push_back('(');
            generate(remainingNumberOfOpenBrackets - 1, usedOpenBrackets + 1, ans, s);
            s.pop_back();
            if(usedOpenBrackets > 0){
                s.push_back(')');
                generate(remainingNumberOfOpenBrackets, usedOpenBrackets - 1, ans, s);
                s.pop_back();
            }
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        generate(n, 0, ans, s);
        return ans;
    }
};