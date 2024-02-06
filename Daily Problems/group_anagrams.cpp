/*

Link: https://leetcode.com/problems/group-anagrams/description/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 0){
            return {{""}};
        }
        if(strs.size() == 1){
            return {strs};
        }
        vector<pair<vector<int>,int>>v;
        for(int i=0; i<strs.size(); i++){
            vector<int>temp(26, 0);
            for(auto j: strs[i]){
                temp[j-'a']++;
            }
            v.push_back({temp, i});
        }
        sort(v.begin(), v.end());
        vector<vector<string>>ans;
        vector<string>res;
        res.push_back(strs[v[0].second]);
        for(int i=1; i<v.size(); i++){
            if(v[i-1].first == v[i].first){
                res.push_back(strs[v[i].second]);
            } else {
                ans.push_back(res);
                res.clear();
                res.push_back(strs[v[i].second]);
            }
            if(i == v.size()-1){
                ans.push_back(res);
            }
        }
        return ans;
    }
};