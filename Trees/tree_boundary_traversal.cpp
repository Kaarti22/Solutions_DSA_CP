/*
Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8

As you can see we have not taken the right subtree. 

Your Task:
This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

#include <bits/stdc++.h>
using namespace std;

// A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
private:
    void leftTraversal(Node* node, vector<int>& ans){
        Node* curr = node->left;
        while(curr){
            if(!(!curr->left && !curr->right)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void inorder(Node* node, vector<int>& ans){
        if(!node->left && !node->right){
            ans.push_back(node->data); 
            return;
        }
        if(node->left) inorder(node->left, ans);
        if(node->right) inorder(node->right, ans);
    }
    
    void rightTraversal(Node* node, vector<int>& ans){
        Node* curr = node->right;
        vector<int>temp;
        while(curr){
            if(!(!curr->left && !curr->right)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }

public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(!root) return {};
        if(!(!root->left && !root->right)) ans.push_back(root->data);
        leftTraversal(root, ans);
        inorder(root, ans);
        rightTraversal(root, ans);
        return ans;
    }
};