/*
Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.

 

Examples:
 

Input :
arr[] = {10, 5, 2, 7, 1, 9}, k = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Input : 
arr[] = {-1, 2, 3}, k = 6
Output : 0
Explanation: 
There is no such sub-array with sum 6.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

 

Constraints:
1<=n<=105
-105<=arr[i], K<=105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<long long, int>prefixSum;
        long long sum = 0;
        int maxLen = 0;
        for(int i=0; i<N; i++){
            sum += (A[i] * 1ll);
            if(sum == (1ll * K)){
                maxLen = max(maxLen, i+1);
            }
            long long rem = sum - (K * 1ll);
            if(prefixSum.find(rem) != prefixSum.end()){
                int len = i - prefixSum[rem];
                maxLen = max(maxLen, len);
            }
            if(prefixSum.find(sum) == prefixSum.end()){
                prefixSum[sum] = i;
            }
        }
        return maxLen;
    } 
};