/*
Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/description/

A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>m;
        string t = "";
        for(auto it: s1){
            if(it == ' '){
                m[t]++;
                t = "";
            } else {
                t += it;
            }
        }
        m[t]++;
        t = "";
        for(auto it: s2){
            if(it == ' '){
                m[t]++;
                t = "";
            } else {
                t += it;
            }
        }
        m[t]++;
        vector<string>ans;
        for(auto it: m){
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};