/*
Link: https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%3BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array

Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x is defined as the largest element k in arr[] such that k is smaller than or equal to x. Find the index of k(0-based indexing).

Examples

Input: n = 7, x = 0 arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less than 0 is found. So output is "-1".
Input: n = 7, x = 5 arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is 2 (i.e k = 2), whose index is 1(0-based indexing).
Your Task:
The task is to complete the function findFloor() which returns an integer denoting the index value of K or return -1 if there isn't any such number.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ n ≤ 107
1 ≤ arr[i] ≤ 1018
0 ≤ x ≤ arr[n-1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x) {
        long long low = 0, high = n-1;
        while(low < high){
            long long mid = low + (high - low)/2;
            if(v[mid] < x){
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if(v[high] <= x) return high;
        if(v[low] <= x) return low;
        if(low > 0 && v[low-1] <= x) return low-1;
        return -1;
    }
};