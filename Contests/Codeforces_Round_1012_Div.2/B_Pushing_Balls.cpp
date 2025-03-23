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
    void method(vector<string>& v, int n, int m){
        vvi vis(n, vi(m, 0));
        rep(i,0,n){
            if(v[i][0] == '1'){
                rep(j,0,m){
                    if(v[i][j] == '0') break;
                    vis[i][j] = 1;
                }
            }
        }
        rep(j,0,m){
            if(v[0][j] == '1'){
                rep(i,0,n){
                    if(v[i][j] == '0') break;
                    vis[i][j] = 1; 
                }
            }
        }
        rep(i,0,n){
            rep(j,0,m){
                if(vis[i][j] == 0 && v[i][j] == '1'){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        cout<<"YES"<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m;
        cin>>n>>m;
        vector<string>v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        Kaarti *ob = new Kaarti;
        ob->method(v, n, m);
    }
    return 0;
}