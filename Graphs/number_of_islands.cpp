/*

Link: https://leetcode.com/problems/number-of-islands/description/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
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
    return (a+b)%MOD;
}

int msub(int a,int b){
    return (((a-b)%MOD)+MOD)%MOD;
}

int mmul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

vector<vector<int>>dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void bfs(int r, int c, vvi& vis, vvi& grid){
    int n = grid.size();
    int m = grid[0].size();
    vis[r][c] = 1;
    queue<pair<int,int>>q;
    q.push({r,c});
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        rep(i,0,4){
            int newrow = row + dir[i][0];
            int newcol = col + dir[i][1];
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1 && !vis[newrow][newcol]){
                q.push({newrow, newcol});
                vis[newrow][newcol] = 1;
            }
        }
    }
}

// Space complexity = O(n^2) + O(n^2)
// Time complexity = O(n^2) + O(n^2)
int numIslands(vvi& grid){
    int n = grid.size();
    int m = grid[0].size();
    vvi vis(n, vi(m, 0));
    int c = 0;
    rep(i,0,n){
        rep(j,0,m){
            if(!vis[i][j] && grid[i][j] == 1){
                c++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return c;
}

int main(){
    int n,m;
    cin>>n>>m;
    vvi grid(n, vi(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>grid[i][j];
        }
    }
    cout<<numIslands(grid)<<endl;
    return 0;
}