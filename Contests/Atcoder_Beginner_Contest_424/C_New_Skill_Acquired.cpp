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
    void method(vvi& v, int n){
        vvi ind(n+1, vi());
        rep(i,0,n){
            if(v[i][0] == 0 && v[i][1] == 0) continue;
            ind[v[i][0]].pb(i+1);
            ind[v[i][1]].pb(i+1);
        }
        queue<int> q;
        vi vis(n+1, 0);
        rep(i,0,n){
            if(v[i][0] == 0 && v[i][1] == 0){
                vis[i+1] = 1;
                for(auto j: ind[i+1]){
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
        while(!q.empty()){
            int index = q.front();
            q.pop();
            for(auto j: ind[index]){
                if(vis[j] == 0){
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
        int ans = 0;
        rep(i,1,n+1){
            if(vis[i] == 1){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vvi v(n, vi(2));
    rep(i,0,n){
        cin>>v[i][0]>>v[i][1];
    }
    Kaarti ob;
    ob.method(v, n);
    return 0;
}