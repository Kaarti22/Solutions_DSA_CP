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

int main(){
    // Adjacency matrix - O(n^2) space complexity
    int n,m;
    cin>>n>>m;
    vvi adj(n+1, vi(n+1, 0));
    rep(i,0,m){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1; // if undirected
        // if weighted, store the weight instead of 1
    }

    // Adjacency list - O(2*E) space complexity for undirected and O(E) for directed graph
    int n,m;
    cin>>n>>m;
    vi adjacent[n+1]; // creating vector of lists
    rep(i,0,m){
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); // if undirected
        // if weighted, store it as a pair of adjNode, weight
    }
    return 0;
}