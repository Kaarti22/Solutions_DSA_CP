/*
Link: https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings

Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Example 1:

Input: S = "aba", K = 2
Output:3
Explanation:The substrings are: "ab", "ba" and "aba".
Input: S = "abaaca", K = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a". 
Your Task:
You don't need to read input or print anything. Your task is to complete the function substrCount() which takes the string S and an integer K as inputs and returns the number of substrings having exactly K distinct characters.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 106
1 ≤ K ≤ 26
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  private:
    long long atMostK(string s, int k){
        if(k < 0) return 0;
        long long ans = 0;
        int n = s.size();
        vector<int>v(26, 0);
        int count = 0;
        int i = 0, j = 0;
        while(j < n){
            v[s[j] - 'a']++;
            if(v[s[j] - 'a'] == 1) count++;
            while(count > k){
                v[s[i] - 'a']--;
                if(v[s[i] - 'a'] == 0) count--;
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    
  public:
    long long int substrCount (string s, int k) {
        return atMostK(s, k) - atMostK(s, k-1);
    }
};