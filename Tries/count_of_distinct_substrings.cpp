/*
Link: https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1

Given a string of length N of lowercase alphabet characters. The task is to complete the function countDistinctSubstring(), which returns the count of total number of distinct substrings of this string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case in a new line, output will be an integer denoting count of total number of distinct substrings of this string.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function countDistinctSubstring().

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 1000

Example(To be used only for expected output):
Input:
2
ab
ababa

Output:
4
10

Exaplanation:
Testcase 1: For the given string "ab" the total distinct substrings are: "", "a", "b", "ab".
*/

#include <bits/stdc++.h>
using namespace std;

/*You are required to complete this method */
class Trie {
private:
    struct Node {
        unordered_map<char, Node*> links;
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
    
public:
    Trie() {
        root = new Node();
    }
    
    int insertSuffix(string& word, int start){
        int n = word.size();
        int newNodes = 0;
        Node* node = root;
        for(int i=start; i<n; i++){
            if(!containsKey(node, word[i])){
                put(node, word[i], new Node());
                newNodes++;
            }
            node = get(node, word[i]);
        }
        return newNodes;
    }
    
    int countDistinctSubstrings(string& s){
        int count = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            count += insertSuffix(s, i);
        }
        return count + 1;
    }
};

int countDistinctSubstring(string s) {
    Trie trie;
    return trie.countDistinctSubstrings(s);
}