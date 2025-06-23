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
        int maxi = 0;
        rep(i,0,n){
            rep(j,0,m){
                maxi = max(maxi, v[i][j]);
            }
        }
        vvi occ(n);
        vi cols(m, 0);
        vi rows(n, 0);
        vi check(m, 0);
        rep(i,0,n){
            rep(j,0,m){
                if(v[i][j] == maxi){
                    occ[i].pb(j);
                    cols[j]++;
                    rows[i]++;
                    check[j] = 1;
                }
            }
        }
        int dc = 0;
        rep(j,0,m){
            if(check[j] == 1){
                dc++;
            }
        }
        int dr = 0;
        rep(i,0,n){
            if(rows[i] > 0){
                dr++;
            }
        }
        vi x(n, 0);
        rep(i,0,n){
            for(auto it: occ[i]){
                if(cols[it] == 1){
                    x[i]++;
                }
            }
        }
        vi y(m, 0);
        rep(i,0,n){
            if(rows[i] == 1){
                if(!occ[i].empty()){
                    y[occ[i][0]]++;
                }
            }
        }
        rep(i,0,n){
            if(dc - x[i] <= 1){
                cout<<maxi-1<<endl;
                return;
            }
        }
        rep(j,0,m){
            if(dr - y[j] <= 1){
                cout<<maxi-1<<endl;
                return;
            }
        }
        cout<<maxi<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m;
        cin>>n>>m;
        vvi v(n, vi(m));
        rep(i,0,n){
            rep(j,0,m){
                cin>>v[i][j];
            }
        }
        Kaarti ob;
        ob.method(v, n, m);
    }
    return 0;
}