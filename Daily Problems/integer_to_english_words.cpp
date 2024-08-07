/*
Link: https://leetcode.com/problems/integer-to-english-words/description/

Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, string> ones = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
    };

    unordered_map<int, string> tens = {
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
    };

    string getString(int n) {
        vector<string> ans;
        int hundreds = n / 100;
        if(hundreds) {
            ans.push_back(ones[hundreds] + " Hundred");
        }
        int lastTwo = n % 100;
        if(lastTwo >= 20) {
            int ten = lastTwo / 10;
            int one = lastTwo % 10;
            ans.push_back(tens[ten * 10]);
            if(one) {
                ans.push_back(ones[one]);
            }
        } else if(lastTwo != 0) {
            ans.push_back(ones[lastTwo]);
        }
        string s = "";
        for(auto it: ans) {
            s += it;
            s += " ";
        }
        if (!s.empty()) s.pop_back();
        return s;
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> post = {"", " Thousand", " Million", " Billion"};
        int i = 0;
        vector<string> ans;
        while(num) {
            int digits = num % 1000;
            string temp = getString(digits);
            if(temp.size() > 0){
                string s = temp + post[i];
                ans.push_back(s);
            }
            num /= 1000;
            i++;
        }
        reverse(ans.begin(), ans.end());
        string res = "";
        for(auto it: ans) {
            res += it;
            res += " ";
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};


