/*
Link: https://leetcode.com/problems/word-ladder-ii/description/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 105.
*/

// Accepted in GFG but TLE in leetcode... no reason

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s(wordList.begin(), wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>v = q.front();
            q.pop();
            if(v.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    s.erase(it);
                }
                usedOnLevel.clear();
            }
            string word = v.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(v);
                } else if(ans[0].size() == v.size()) {
                    ans.push_back(v);
                }
            }
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        v.push_back(word);
                        q.push(v);
                        usedOnLevel.push_back(word);
                        v.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};