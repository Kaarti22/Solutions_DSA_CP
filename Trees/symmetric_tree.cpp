/*
Link: https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isSymmetricBothSides(TreeNode* leftNode, TreeNode* rightNode){
        if(!leftNode || !rightNode) return leftNode == rightNode;
        return (leftNode->val == rightNode->val) && isSymmetricBothSides(leftNode->left, rightNode->right) && isSymmetricBothSides(leftNode->right, rightNode->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricBothSides(root->left, root->right);
    }
};