/*
Link: https://www.geeksforgeeks.org/problems/graph-and-vertices/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=graph-and-vertices

Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.

 

Example 1:

Input: 2
Output: 2
Example 2:

Input: 5
Output: 1024
 

Your Task:

Complete the function count() which takes an integer n as input and return the count of total number of graphs possible.

 

Expected Time Complexity: O(1)

Expected Space Complexity: O(1)

 

Constraints:

1<=n<=10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long count(int n) {
        return powl(2, (n * (n-1))/2);
    }
};