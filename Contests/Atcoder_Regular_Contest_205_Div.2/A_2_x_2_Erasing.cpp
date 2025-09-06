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
    struct Prefix2D {
        vvi prefix;
        int n, m;

        Prefix2D(int n, int m): n(n), m(m){
            prefix.assign(n+1, vi(m+1, 0));
        }

        void build(vvi& v){
            rep(i,1,n+1){
                rep(j,1,m+1){
                    prefix[i][j] = v[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
                }
            }
        }

        int query(int x1, int y1, int x2, int y2){
            if(x1 > x2 || y1 > y2) return 0;
            return prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
        }
    };

public:
    void method(vector<string>& s, vvi& q, int n){
        vvi v(n-1, vi(n-1, 0));
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(s[i][j] == '.' && s[i][j+1] == '.' && s[i+1][j] == '.' && s[i+1][j+1] == '.'){
                    v[i][j] = 1;
                }
            }
        }
        Prefix2D ps(n-1, n-1);
        ps.build(v);
        for(auto it: q){
            int x1 = it[0], x2 = it[1] - 1, y1 = it[2], y2 = it[3] - 1;
            cout<<ps.query(x1, y1, x2, y2)<<endl;
        }
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin>>n>>q;
    vector<string>v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    vvi queries(q, vi(4));
    rep(i,0,q){
        rep(j,0,4){
            cin>>queries[i][j];
        }
    }
    Kaarti ob;
    ob.method(v, queries, n);
    return 0;
}