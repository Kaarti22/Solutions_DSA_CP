/*
Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3
Output: 
1 2 
1 3 
Explanation: 
All possible paths:
1->2
1->3
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 
10 20 40 
10 20 60 
10 30 
Your Task:
Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. (All the paths are printed in new lines by the driver's code.)

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the tree)

Constraints:
1<=n<=104
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  private:
    void generatePaths(Node* node, vector<int>& path, vector<vector<int>>& ans){
        if(!node) return;
        path.push_back(node->data);
        if(!node->left && !node->right){
            ans.push_back(path);
        } else {
            generatePaths(node->left, path, ans);
            generatePaths(node->right, path, ans);
        }
        path.pop_back();
    }  
    
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans;
        vector<int>path;
        generatePaths(root, path, ans);
        return ans;
    }
};