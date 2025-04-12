/*
Link: https://leetcode.com/problems/find-the-count-of-good-integers/description/?envType=daily-question&envId=2025-04-12

You are given two positive integers n and k.

An integer x is called k-palindromic if:

x is a palindrome.
x is divisible by k.
An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

Return the count of good integers containing n digits.

Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.

 

Example 1:

Input: n = 3, k = 5

Output: 27

Explanation:

Some of the good integers are:

551 because it can be rearranged to form 515.
525 because it is already k-palindromic.
Example 2:

Input: n = 1, k = 4

Output: 2

Explanation:

The two good integers are 4 and 8.

Example 3:

Input: n = 5, k = 6

Output: 2468

 

Constraints:

1 <= n <= 10
1 <= k <= 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    #define ll long long
    ll ans = 0;
    unordered_set<ll> done;
    vector<ll> fact;

    void precomputeFactorial(){
        fact[0] = 1;
        fact[1] = 1;
        for(ll i=2; i<=10; i++){
            fact[i] = i * fact[i-1];
        }
    }

    ll countAllPermutations(vector<ll>& freq, int n){
        ll count = fact[n];
        for(int i=0; i<=9; i++){
            count /= fact[freq[i]];
        }
        return count;
    }

    ll allArrangements(string num, int n){
        sort(num.begin(), num.end());
        if(done.count(stoll(num))){
            return 0;
        }
        done.insert(stoll(num));
        vector<ll> freq(10);
        for(auto it: num){
            freq[it - '0']++;
        }
        ll total = countAllPermutations(freq, n);
        ll invalid = 0;
        if(freq[0] > 0){
            freq[0]--;
            invalid = countAllPermutations(freq, n-1);
        }
        return total - invalid;
    }

    bool isPalindrome(string& num, int n, int k){
        return (stoll(num) % k == 0);
    }

    void generatePalindromes(int pos, int n, string& num, int k){
        if(pos >= (n + 1)/2){
            if(isPalindrome(num, n, k)){
                ans += allArrangements(num, n);
            }
            return;
        }
        char start = pos == 0 ? '1' : '0';
        while(start <= '9'){
            num[pos] = start;
            num[n-pos-1] = start;
            generatePalindromes(pos + 1, n, num, k);
            start++;
        }
        num[pos] = ' ';
    }

public:
    long long countGoodIntegers(int n, int k) {
        fact = vector<ll>(11);
        precomputeFactorial();
        string num(n, ' ');
        generatePalindromes(0, n, num, k);
        return ans;
    }
};