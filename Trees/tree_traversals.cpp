/*
Link: https://www.naukri.com/code360/problems/tree-traversal_981269?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

You have been given a Binary Tree of 'N'

nodes, where the nodes have integer values.



Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.
*/

#include <bits/stdc++.h>
using namespace std;


// Following is Binary Tree Node structure:
class TreeNode{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode *left, TreeNode *right) :data(x), left(left), right(right) {}
};

void inOrder(TreeNode* root, vector<int>& v){
    if(!root) return;
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

void preOrder(TreeNode* root, vector<int>& v){
    if(!root) return;
    v.push_back(root->data);
    preOrder(root->left, v);
    preOrder(root->right, v);
}

void postOrder(TreeNode* root, vector<int>& v){
    if(!root) return;
    postOrder(root->left, v);
    postOrder(root->right, v);
    v.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int>inOrderTraversal, preOrderTraversal, postOrderTraversal;
    inOrder(root, inOrderTraversal);
    preOrder(root, preOrderTraversal);
    postOrder(root, postOrderTraversal);
    vector<vector<int>> ans = {inOrderTraversal, preOrderTraversal, postOrderTraversal};
    return ans;
}