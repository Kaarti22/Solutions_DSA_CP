/*
Link: https://leetcode.com/problems/powx-n/description/

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double multiply(double x, int n){
        if(n == 0) return 1;
        double ans = multiply(x, n/2);
        if(n & 1) ans = ans * ans * x;
        else ans = ans * ans;
        return ans;
    }

public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        double ans = multiply(x, abs(n));
        if(n >= 0) return ans;
        return 1 / ans;
    }
};