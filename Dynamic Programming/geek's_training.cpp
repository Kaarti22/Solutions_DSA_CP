/*
Link: https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.

Example:
Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
Output:11
Explanation:Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum point is 11.
Expected Time Complexity: O(3*n)
Expected Space Complexity: O(3*n)

Constraint:
1 <=  arr.size <= 105
1 <=  arr[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        int dp[n][3];
        dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];
        for(int i=1; i<n; i++){
            dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = arr[i][2] + max(dp[i-1][0], dp[i-1][1]);
        }
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};