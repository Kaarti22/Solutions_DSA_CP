/*

Link: https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. 
You don't need to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both strings contain lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int search(string pat, string txt) {
	    int ans = 0;
	    map<int, int>m;
	    for(auto i: pat){
	        m[i]++;
	    }
	    int n = txt.size(), k = pat.size();
	    map<int, int>temp;
	    for(int i=0; i<k; i++){
	        temp[txt[i]]++;
	    }
	    if(m == temp) ans++;
	    int i = 0, j = k - 1;
	    while(j < n-1){
	        temp[txt[i]]--;
	        if(temp[txt[i]] == 0){
	            temp.erase(txt[i]);
	        }
	        i++, j++;
	        temp[txt[j]]++;
	        if(m == temp) ans++;
	    }
	    return ans;
	}
};