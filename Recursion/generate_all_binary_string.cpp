/*
Link: https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

A binary string is that string which contains only 0 and 1.

Example 1:

Input:
N = 3
Output:
000 , 001 , 010 , 100 , 101
Explanation:
None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively. 
Your Task:

You don't need to read input or print anything. Your task is to complete the function generateBinaryStrings() which takes an integer N as input and returns a list of all valid binary strings in lexicographically increasing order.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 20
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void generate(int ind, int num, string& s, vector<string>& ans, bool f){
        if(ind == num){
            ans.push_back(s);
            return;
        }
        if(f){
            s += "1";
            generate(ind + 1, num, s, ans, !f);
            s.pop_back();
            s += "0";
            generate(ind + 1, num, s, ans, f);
            s.pop_back();
        } else {
            s += "0";
            generate(ind + 1, num, s, ans, !f);
            s.pop_back();
        }
    }

public:
    vector<string> generateBinaryStrings(int num){
        vector<string>ans;
        string s = "";
        generate(0, num, s, ans, true);
        sort(ans.begin(), ans.end());
        return ans;
    }
};