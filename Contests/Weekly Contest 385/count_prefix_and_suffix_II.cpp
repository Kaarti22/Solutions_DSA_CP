/*

Link: https://leetcode.com/contest/weekly-contest-385/problems/count-prefix-and-suffix-pairs-ii/

You are given a 0-indexed string array words.

Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

Example 1:

Input: words = ["a","aba","ababa","aa"]
Output: 4
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
Therefore, the answer is 4.
Example 2:

Input: words = ["pa","papa","ma","mama"]
Output: 2
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("pa", "papa") is true.
i = 2 and j = 3 because isPrefixAndSuffix("ma", "mama") is true.
Therefore, the answer is 2.  
Example 3:

Input: words = ["abab","ab"]
Output: 0
Explanation: In this example, the only valid index pair is i = 0 and j = 1, and isPrefixAndSuffix("abab", "ab") is false.
Therefore, the answer is 0.
 

Constraints:

1 <= words.length <= 10^5
1 <= words[i].length <= 10^5
words[i] consists only of lowercase English letters.
The sum of the lengths of all words[i] does not exceed 5 * 10^5.
*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
// #define M 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ll long long
#define all(v) v.begin(),v.end()

void inparr(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void disarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void disvec(vi v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

// int madd(int a,int b) {
//     return (a+b)%M;
// }

// int msub(int a,int b){
//     return (((a-b)%M)+M)%M;
// }

// int mmul(int a,int b){
//     return ((a%M)*(b%M))%M;
// }

class StringHash{
    public:
        vector<long long>ps1,ps2;
        long long Q1 = 271, Q2 = 277, M1 = 1000000007, M2 = 998244353;
        StringHash(string s){
            ps1 = vector<long long>(s.size()+1);
            ps2 = vector<long long>(s.size()+1);
            for(int i=1; i<=s.size(); i++){
                long long c = s[i-1] + 1;
                ps1[i] = ((Q1 * ps1[i-1]) + c) % M1;
                ps2[i] = ((Q2 * ps2[i-1]) + c) % M2;
            }
        }
        long long powxy(long long x, long long y, long long M){
            if(y == 0){
                return 1;
            }
            if(y % 2 == 1){
                return (x * powxy(x, y-1, M)) % M;
            }
            long long t = powxy(x, y/2, M);
            return (t * t) % M;
        }
        long long substrHash1(int firstIndex, int lastIndex){
            long long rem = (powxy(Q1, lastIndex - firstIndex + 1, M1) * ps1[firstIndex]) % M1;
            return (ps1[lastIndex + 1] - rem + M1) % M1;
        }
        long long substrHash2(int firstIndex, int lastIndex){
            long long rem = (powxy(Q2, lastIndex - firstIndex + 1, M2) * ps2[firstIndex]) % M2;
            return (ps2[lastIndex + 1] - rem + M2) % M2;
        }
        pair<long long, long long>substrHash(int firstIndex, int lastIndex){
            return {substrHash1(firstIndex, lastIndex), substrHash2(firstIndex, lastIndex)};
        }
};

long long countPrefixSuffuxPairs(vector<string>& words){
    int n = words.size();
    map<pair<long long, long long>,int>count;
    long long ans = 0;
    for(int i=n-1; i>=0; i--){
        int m = words[i].size();
        StringHash sh(words[i]);
        auto hash = sh.substrHash(0, m-1);
        if(count.find(hash) != count.end()){
            ans += count[hash];
        }
        for(int j=1; j<=m; j++){
            auto preHash = sh.substrHash(0, j-1);
            auto sufHash = sh.substrHash(m-j, m-1);
            if(preHash == sufHash){
                count[preHash]++;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string>words(n);
    rep(i,0,n){
        cin>>words[i];
    }
    cout<<countPrefixSuffuxPairs(words)<<endl;
    return 0;
}