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

const int INF = 4e17;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vvi dist(n+1, vi(n+1, INF));
    rep(i,1,n+1) dist[i][i] = 0;
    rep(i,0,m){
        int u, v, c;
        cin>>u>>v>>c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }
    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int k, T;
    cin>>k>>T;
    vi check(n+1, 0);
    rep(i,0,k){
        int d;
        cin>>d;
        check[d] = 1;
    }
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int u, v, t;
            cin>>u>>v>>t;
            rep(i,1,n+1){
                rep(j,1,n+1){
                    int p1 = INF, p2 = INF;
                    if(dist[i][u] != INF && dist[v][j] != INF){
                        p1 = dist[i][u] + t + dist[v][j];
                    }
                    if(dist[i][v] != INF && dist[u][j] != INF){
                        p2 = dist[i][v] + t + dist[u][j];
                    }
                    dist[i][j] = min({dist[i][j], p1, p2});
                }
            }
        } else if(type == 2){
            int x;
            cin>>x;
            check[x] = 1;
        } else {
            vi newDist(n+1, INF);
            rep(i,1,n+1){
                rep(j,1,n+1){
                    if(check[j]){
                        newDist[i] = min(newDist[i], dist[i][j]);
                    }
                }
            }
            int sum = 0;
            rep(i,1,n+1){
                rep(j,1,n+1){
                    int final_dist = dist[i][j];
                    int path = INF;
                    if(newDist[i] != INF && newDist[j] != INF){
                        path = newDist[i] + T + newDist[j];
                    }
                    final_dist = min(final_dist, path);
                    if(final_dist < INF){
                        sum += final_dist;
                    }
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}