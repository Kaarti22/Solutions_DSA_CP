/*
Link: https://www.geeksforgeeks.org/problems/longest-valid-word-with-all-prefixes/1

Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. If multiple strings have the same maximum length, return the lexicographically smallest one.

If no such string is found, return an empty string.

Examples:

Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: "pros" 
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present.
Input: words[] = ["geeks", "gfg", "geeksforgeeks"]
Output: ""
Explanation: No valid strings for all their prefixes present in the words array.
Constraints:
1 <= words.size <= 1000
1 <= words[i].size <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    class Trie {
    private:
        struct Node {
            Node* links[26];
            bool flag = false;
        };
        
        Node* root;
        
        bool containsKey(Node* node, char ch){
            return node->links[ch - 'a'] != nullptr;
        }
        
        void put(Node* node, char ch, Node* newNode){
            node->links[ch - 'a'] = newNode;
        }
        
        Node* get(Node* node, char ch){
            return node->links[ch - 'a'];
        }
        
        void endWord(Node* node){
            node->flag = true;
        }
        
    public:
        Trie () {
            root = new Node();
        }
        
        void insertWord(string word){
            Node* node = root;
            for(auto ch: word){
                if(!containsKey(node, ch)){
                    put(node, ch, new Node());
                }
                node = get(node, ch);
            }
            endWord(node);
        }
        
        string findEveryPrefix(string word){
            string ans = "";
            Node* node = root;
            for(auto ch: word){
                if(!containsKey(node, ch)){
                    return "";
                }
                node = get(node, ch);
                if(!node->flag){
                    return "";
                }
                ans.push_back(ch);
            }
            return ans;
        }
    };
    
public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for(auto word: words){
            trie.insertWord(word);
        }
        string ans = "";
        for(auto word: words){
            string s = trie.findEveryPrefix(word);
            if(s == "") continue;
            if(s.size() > ans.size()){
                ans = s;
            } else if(s.size() == ans.size() && s < ans){
                ans = s;
            }
        }
        return ans;
    }
};
