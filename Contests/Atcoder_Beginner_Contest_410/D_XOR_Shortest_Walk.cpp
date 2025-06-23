#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
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

class Kaarti{   
public:
    void method(vvi& v, int n, int m){
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
        for(auto it: v){
            adj[it[0]].pb({it[1], it[2]});
        }
        vvi vis(n+1, vi(1024, 0));
        queue<pair<int, int>> q;
        vis[1][0] = 1;
        q.push({1, 0});
        while(!q.empty()){
            int node = q.front().first, cost = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                int adjNode = it.first, wt = it.second;
                int x = cost ^ wt;
                if(vis[adjNode][x] == 0){
                    vis[adjNode][x] = 1;
                    q.push({adjNode, x});
                }
            }
        }
        rep(i,0,1024){
            if(vis[n][i] == 1){
                cout<<i<<endl;
                return;
            }
        }
        cout<<-1<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vvi v(m, vi(3));
    rep(i,0,m){
        rep(j,0,3){
            cin>>v[i][j];
        }
    }
    Kaarti ob;
    ob.method(v, n, m);
    return 0;
}