/*
Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1
*/

/*
Time complexity ~ O(nlogm) where m = 32
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

public:
    Trie (){
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

    int findMaximumXOR(int number){
        Node* node = root;
        int maxiXor = 0;
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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        Trie trie;
        trie.insertVal(nums[0]);
        for(int i=1; i<n; i++){
            ans = max(ans, trie.findMaximumXOR(nums[i]));
            trie.insertVal(nums[i]);
        }
        return ans;
    }
};