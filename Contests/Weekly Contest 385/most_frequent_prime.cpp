/*

Link: https://leetcode.com/contest/weekly-contest-385/problems/most-frequent-prime/

You are given a m x n 0-indexed 2D matrix mat. From every cell, you can create numbers in the following way:

There could be at most 8 paths from the cells namely: east, south-east, south, south-west, west, north-west, north, and north-east.
Select a path from them and append digits in this path to the number being formed by traveling in this direction.
Note that numbers are generated at every step, for example, if the digits along the path are 1, 9, 1, then there will be three numbers generated along the way: 1, 19, 191.
Return the most frequent prime number greater than 10 out of all the numbers created by traversing the matrix or -1 if no such prime number exists. If there are multiple prime numbers with the highest frequency, then return the largest among them.

Note: It is invalid to change the direction during the move.

Example 1:



Input: mat = [[1,1],[9,9],[1,1]]
Output: 19
Explanation: 
From cell (0,0) there are 3 possible directions and the numbers greater than 10 which can be created in those directions are:
East: [11], South-East: [19], South: [19,191].
Numbers greater than 10 created from the cell (0,1) in all possible directions are: [19,191,19,11].
Numbers greater than 10 created from the cell (1,0) in all possible directions are: [99,91,91,91,91].
Numbers greater than 10 created from the cell (1,1) in all possible directions are: [91,91,99,91,91].
Numbers greater than 10 created from the cell (2,0) in all possible directions are: [11,19,191,19].
Numbers greater than 10 created from the cell (2,1) in all possible directions are: [11,19,19,191].
The most frequent prime number among all the created numbers is 19.
Example 2:

Input: mat = [[7]]
Output: -1
Explanation: The only number which can be formed is 7. It is a prime number however it is not greater than 10, so return -1.
Example 3:

Input: mat = [[9,7,8],[4,6,5],[2,8,6]]
Output: 97
Explanation: 
Numbers greater than 10 created from the cell (0,0) in all possible directions are: [97,978,96,966,94,942].
Numbers greater than 10 created from the cell (0,1) in all possible directions are: [78,75,76,768,74,79].
Numbers greater than 10 created from the cell (0,2) in all possible directions are: [85,856,86,862,87,879].
Numbers greater than 10 created from the cell (1,0) in all possible directions are: [46,465,48,42,49,47].
Numbers greater than 10 created from the cell (1,1) in all possible directions are: [65,66,68,62,64,69,67,68].
Numbers greater than 10 created from the cell (1,2) in all possible directions are: [56,58,56,564,57,58].
Numbers greater than 10 created from the cell (2,0) in all possible directions are: [28,286,24,249,26,268].
Numbers greater than 10 created from the cell (2,1) in all possible directions are: [86,82,84,86,867,85].
Numbers greater than 10 created from the cell (2,2) in all possible directions are: [68,682,66,669,65,658].
The most frequent prime number among all the created numbers is 97.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 6
1 <= mat[i][j] <= 9

*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define M 1000000007
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

int madd(int a,int b) {
    return (a+b)%M;
}

int msub(int a,int b){
    return (((a-b)%M)+M)%M;
}

int mmul(int a,int b){
    return ((a%M)*(b%M))%M;
}

bool isPrime(int n){
    if(n <= 1){
        return 0;
    }
    for(int i=2; i*i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int mostFrequentPrime(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
    int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
    map<int,int>count;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<8; k++){
                int x = i, y = j;
                int num = mat[x][y];
                while(1){
                    x += dx[k], y+= dy[k];
                    if(x < 0 || x >= n || y < 0 || y >= m){
                        break;
                    }
                    num = num*10 + mat[x][y];
                    if(isPrime(num)){
                        count[num]++;
                    }
                }
            }
        }
    }
    if(count.empty()){
        return -1;
    }
    int ans = 0, freq = 0;
    for(auto i: count){
        if(i.second >= freq){
            ans = i.first;
            freq = i.second;
        }
    }
    return ans;
}

int main(){
    int m,n;
    cin>>m>>n;
    vvi v(m, vi(n));
    rep(i,0,m){
        rep(j,0,n){
            cin>>v[i][j];
        }
    }
    cout<<mostFrequentPrime(v)<<endl;
    return 0;
}