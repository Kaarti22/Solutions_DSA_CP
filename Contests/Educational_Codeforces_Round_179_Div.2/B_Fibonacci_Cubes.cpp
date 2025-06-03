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
        vi f(n+1);
        f[1] = 1, f[2] = 2;
        rep(i,3,n+1){
            f[i] = f[i-1] + f[i-2];
        }
        for(auto it: v){
            sort(all(it));
            int h = it[2], w = it[0], l = it[1];
            if(f[n] > w || f[n] + f[n-1] > h){
                cout<<"0";
            } else {
                cout<<"1";
            }
        }
        cout<<endl;
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
        vvi v(m, vi(3));
        rep(i,0,m) cin>>v[i][0]>>v[i][1]>>v[i][2];
        Kaarti ob;
        ob.method(v, n, m);
    }
    return 0;
}