/*
Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)


Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    vector<int>topoSort(int V, vector<int>adj[]){
        int indegree[V] = {0};
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        vector<int>indegree(K, 0);
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            bool f = 1;
            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[dict[i+1][j]-'a']++;
                    f = 0;
                    break;
                }
            }
            if(f){
                if(s1.size() > s2.size()){
                    // Order is not possible
                }
            }
        }
        vector<int>topo = topoSort(K, adj);
        string ans = "";
        for(auto it: topo){
            ans += char(it + 'a');
        }
        return ans;
    }
};