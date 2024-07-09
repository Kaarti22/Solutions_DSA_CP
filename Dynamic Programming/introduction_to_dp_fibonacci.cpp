/*
Link: https://www.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp

Geek is learning data structures, and he recently learned about the top-down and bottom-up dynamic programming approaches. Geek is having trouble telling them apart from one another.

When given an integer n, where n is based on a 0-based index, find the nth Fibonacci number.

Every ith number in the series equals the sum of the (i-1)th and (i-2)th numbers, where the first and second numbers are specified as 0 and 1, respectively.

For the given issue, code both top-down and bottom-up approaches.

Note : As the answer might be large, return the final answer modulo 109 + 7

Example 1:

Input:
n = 5
Output: 5
Explanation: 0,1,1,2,3,5 as we can see 5th number is 5.
Example 2:

Input:
n = 6
Output: 8
Explanation: 0,1,1,2,3,5,8 as we can see 6th number is 8.
Constraints:
1 <= n <= 104

Your Task:
You don't need to read input or print anything. Your task is to complete two functions topDown() and bottomUp() which take n as input parameters and return the nth Fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    long long MOD = 1e9 + 7;
    long long dp[10001];
    
  private:
    long long fun(int n, long long dp[]){
        if(n == 0 || n == 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (fun(n-1, dp) + fun(n-2, dp)) % MOD;
    }
  
    
  public:
    long long int topDown(int n) {
        memset(dp, -1, sizeof(dp));
        return fun(n, dp);
    }
    long long int bottomUp(int n) {
        long long dp[n+1];
        dp[0] = 0, dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
        return dp[n];
    }
};