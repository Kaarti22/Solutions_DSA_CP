/*
Link: https://www.geeksforgeeks.org/problems/binary-tree-representation/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-tree-representation

You are given an array nodes. It contains 7 integers, which represents the value of nodes of the binary tree in level order traversal. You are also given a root of the tree which has a value equal to nodes[0].

Your task to construct a binary tree by creating nodes for the remaining 6 nodes.

Example:

Input: 
nodes = [1 2 3 4 5 6 7]
Output: 
         1
       /   \
     2       3
   /  \     /  \
   4  5    6   7
Explanation: 
The 7 node binary tree is represented above.
Your Task:

Complete the function void create_tree(node* root0, vector &vec), which takes a root of a Binary tree and vector array vec containing the values of nodes.

Expected Time Complexity: O(1).

Expected Auxiliary Space: O(1).

Constraints:

vec.length = 7

1<=vec[i]<=100
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        root0->left = newNode(vec[1]);
        root0->right = newNode(vec[2]);
        root0->left->left = newNode(vec[3]);
        root0->left->right = newNode(vec[4]);
        root0->right->left = newNode(vec[5]);
        root0->right->right = newNode(vec[6]);
    }

};