/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside the group.
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

void bfs(vvi &adj, int n, int start, vi &vis){
    queue<int>q;
    q.push(start);
    vis[start] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int j=0; j<adj[0].size(); j++){
            if(adj[node][j] == 1){
                if(!vis[j]){
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }
}

int numberOfProvinces(vvi &adj, int n){
    vi vis(n, 0);
    int c = 0;
    rep(i,0,n){
        if(!vis[i]){
            bfs(adj, n, i, vis);
            c++;
        }
    }
    return c;
}

int main(){
    int n,m;
    cin>>n>>m;
    vvi adj(n+1, vi(n+1, 0));
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // Space Complexity = O(n)
    // Time complexity = O(n) + O(n) + O(2*E) in adj list..
    cout<<numberOfProvinces(adj, n)<<endl;
    return 0;
}