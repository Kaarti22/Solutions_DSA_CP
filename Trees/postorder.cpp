/*
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
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
 
// Recursive solution
class Solution {
private:
    void postOrder(TreeNode* root, vector<int>& v){
        if(!root) return;
        postOrder(root->left, v);
        postOrder(root->right, v);
        v.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postOrder(root, ans);
        return ans;
    }
};

// Iterative solution using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode* >st1;
        stack<int>st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();
            if(!node) break;
            st1.pop();
            st2.push(node->val);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        vector<int>ans;
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};

// Iterative solution using 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode* >st;
        vector<int>ans;
        TreeNode* curr = root;
        while(curr != nullptr || !st.empty()){
            if(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top()->right;
                if(temp == nullptr){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        return ans;
    }
};