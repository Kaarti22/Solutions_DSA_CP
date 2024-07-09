/*
Link: https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be [hi-hj] is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches Stone n.

Examples :
Input: n = 5, k = 3 heights = {10, 30, 40, 50, 20}
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
Input: n = 3, k = 1 heights = {10,20,10}
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minimizeCost() which takes the array height, and integer n, and integer k and returns the minimum energy that is lost.

Expected Time Complexity: O(n*k)
Expected Space Complexity: O(n)

Constraint:
2 <= n <= 103
1 <= k <= 100
1 <= heights[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int>dp(n, 1e9);
        dp[0] = 0;
        if(n == 1) return 0;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=max(0,i-k); j--){
                dp[i] = min(dp[i], dp[j] + abs(height[i] - height[j]));
            }
        }
        return dp[n-1];
    }
};