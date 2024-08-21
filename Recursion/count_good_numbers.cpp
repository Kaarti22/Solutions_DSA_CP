/*
Link: https://leetcode.com/problems/count-good-numbers/description/

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long modMul(long long a, long long b){
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while(exp){
            if(exp % 2 == 1){
                res = (res * base) % MOD;
            }
            exp >>= 1;
            base = (base * base) % MOD;
        }
        return res;
    }

    long long modInv(long long base){
        return modPow(base, MOD-2);
    }

    long long modDiv(long long a, long long b){
        return modMul(a, modInv(b));
    }

public:
    const int MOD = 1e9 + 7;

    long long check(long long n){
        if(n == 1) return 5;
        long long ans = check(n/2);
        if(n & 1){
            if((n/2) & 1) return modMul(modMul(ans, ans), 4);
            else return modMul(modMul(ans, ans), 5);
        }
        if((n/2) & 1) return modDiv(modMul(modMul(ans, ans), 4), 5);
        return modMul(ans, ans);
    }

    int countGoodNumbers(long long n) {
        return (int)check(n);
    }
};