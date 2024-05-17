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

// Space Complexity = O(n)
// Time Complexity = O(n) + (2*E)
vi bfsOfGraph(int V, vi adjacent[], int n){
    vi bfs;
    vi visited(n+1, 0);
    queue<int>q;
    q.push(V);
    visited[V] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.pb(node);
        for(auto it: adjacent[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main(){
    int n,m;
    cin>>n>>m;
    vi adjacent[n+1];
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adjacent[u].pb(v);
        adjacent[v].pb(u);
    }
    int start;
    cin>>start;
    vi bfs = bfsOfGraph(start, adjacent, n);
    for(auto i: bfs){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}