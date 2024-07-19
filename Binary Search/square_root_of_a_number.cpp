/*
Link: https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root

Link: https://leetcode.com/problems/sqrtx/description/

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long low = 0 * 1ll, high = x * 1ll;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if((mid * mid) == x){
                return mid;
            } else if((mid * mid) > x){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = min(low, high);
        if(low * low < x) return low;
        return low - 1;
    }
};