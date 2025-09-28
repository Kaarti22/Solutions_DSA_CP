/*
Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
 

Constraints:

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct Node {
        Node* links[2];
    };

    Node* root;

    bool containsKey(Node* node, int val){
        return node->links[val] != nullptr;
    }

    void put(Node* node, int val, Node* newNode){
        node->links[val] = newNode;
    }

    Node* get(Node* node, int val){
        return node->links[val];
    }

    bool checkTrieEmpty(Node* node){
        return !node->links[0] && !node->links[1];
    }

public:
    Trie () {
        root = new Node();
    }

    void insertVal(int number){
        Node* node = root;
        for(int bit=31; bit>=0; bit--){
            int val = (number >> bit) & 1;
            if(!containsKey(node, val)){
                put(node, val, new Node());
            }
            node = get(node, val);
        }
    }

    int maximumXor(int number){
        int maxiXor = 0;
        Node* node = root;
        if(checkTrieEmpty(node)) return -1;
        for(int bit=31; bit>=0; bit--){
            int val = (number >> bit) & 1;
            int requiredBit = 1 - val;
            if(containsKey(node, requiredBit)){
                maxiXor |= (1 << bit);
                node = get(node, requiredBit);
            } else {
                node = get(node, val);
            }
        }
        return maxiXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int q = queries.size();
        vector<pair<vector<int>, int>> v(q);
        for(int i=0; i<q; i++){
            v[i] = {queries[i], i};
        }
        sort(v.begin(), v.end(), [&](pair<vector<int>, int>& a, pair<vector<int>, int>& b){
            return a.first[1] < b.first[1];
        });
        Trie trie;
        int n = nums.size();
        vector<int> ans(q);
        int i = 0;
        for(int j=0; j<q; j++){
            while(i < n && nums[i] <= v[j].first[1]){
                trie.insertVal(nums[i]);
                i++;
            }
            int ind = v[j].second;
            ans[ind] = trie.maximumXor(v[j].first[0]);
        }
        return ans;
    }
};