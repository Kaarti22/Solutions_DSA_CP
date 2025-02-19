/*
Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19

A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 

Constraints:

1 <= n <= 10
1 <= k <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<string>& v, string& s, int ind){
        int n = s.size();
        char ch = s[ind];
        if(ind > 0){
            char prev = s[ind-1];
            if(prev == 'a'){
                if(ch == 'b'){
                    ch = 'c';
                    s[ind] = ch;
                    char next = 'a';
                    for(int i=ind+1; i<n; i++){
                        s[i] = next;
                        if(next == 'a') next = 'b';
                        else next = 'a';
                    }
                    v.push_back(s);
                    solve(v, s, n-1);
                } else if(ch == 'c'){
                    solve(v, s, ind-1);
                } 
            } else if(prev == 'b'){
                if(ch == 'a'){
                    ch = 'c';
                    s[ind] = ch;
                    char next = 'a';
                    for(int i=ind+1; i<n; i++){
                        s[i] = next;
                        if(next == 'a') next = 'b';
                        else next = 'a';
                    }
                    v.push_back(s);
                    solve(v, s, n-1);
                } else if(ch == 'c'){
                    solve(v, s, ind-1);
                }
            } else {
                if(ch == 'a'){
                    ch = 'b';
                    s[ind] = ch;
                    char next = 'a';
                    for(int i=ind+1; i<n; i++){
                        s[i] = next;
                        if(next == 'a') next = 'b';
                        else next = 'a';
                    }
                    v.push_back(s);
                    solve(v, s, n-1);
                } else if(ch == 'b'){
                    solve(v, s, ind-1);
                }
            }
        } else {
            if(ch == 'a'){
                ch = 'b';
                s[ind] = ch;
                char next = 'a';
                for(int i=ind+1; i<n; i++){
                    s[i] = next;
                    if(next == 'a') next = 'b';
                    else next = 'a';
                }
                v.push_back(s);
                solve(v, s, n-1);
            } else if(ch == 'b'){
                ch = 'c';
                s[ind] = ch;
                char next = 'a';
                for(int i=ind+1; i<n; i++){
                    s[i] = next;
                    if(next == 'a') next = 'b';
                    else next = 'a';
                }
                v.push_back(s);
                solve(v, s, n-1);
            } else {
                return;
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        string s;
        char ch = 'a';
        for(int i=0; i<n; i++){
            s.push_back(ch);
            if(ch == 'a') ch = 'b';
            else ch = 'a';
        }
        vector<string>v;
        v.push_back(s);
        solve(v, s, n-1);
        if(v.size() < k) return "";
        return v[k-1];
    }
};