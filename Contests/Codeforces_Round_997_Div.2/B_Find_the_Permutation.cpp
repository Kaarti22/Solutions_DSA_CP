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
private:
    void solve(vi& ans, vi& vis, vvi& pre, int n, int ind){
        if(ind > n+1) return;
        if(vis[ind] == 1) return;
        for(auto it: pre[ind]){
            solve(ans, vis, pre, n, it);
        }
        ans.pb(ind);
        vis[ind] = 1;
    }

public:
    void method(vector<string>& v, int n){
        vvi pre(n+1, vi());
        rep(i,1,n+1){
            rep(j,i+1,n+1){
                if(v[i][j-1] == '0'){
                    pre[i].pb(j);
                }
            }
        }
        vi ans;
        vi vis(n+1, 0);
        rep(i,1,n+1){
            solve(ans, vis, pre, n, i);
        }
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        vector<string>v(n+1);
        rep(i,1,n+1) cin>>v[i];
        Kaarti *ob = new Kaarti;
        ob->method(v, n);
    }
    return 0;
}