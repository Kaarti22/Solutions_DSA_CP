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
    void method(vvi& v, int n, int q){
        vi a(n);
        rep(i,0,n){
            a[i] = i + 1;
        }
        int k = 0;
        for(auto it: v){
            int type = it[0];
            if(type == 1){
                int ind = (k + it[1] - 1) % n;
                a[ind] = it[2];
            } else if(type == 2){
                int ind = (k + it[1] - 1) % n;
                cout<<a[ind]<<endl;
            } else {
                k = (it[1] + k) % n;
            }
        }
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin>>n>>q;
    vvi v(q);
    rep(i,0,q){
        int type;
        cin>>type;
        if(type == 1){
            int p, x;
            cin>>p>>x;
            v[i] = {type, p, x};
        } else {
            int k;
            cin>>k;
            v[i] = {type, k};
        }
    }
    Kaarti ob;
    ob.method(v, n, q);
    return 0;
}