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

const int INF = 3005;

class Kaarti{
public:
    void method(vvi& v, int n, int h, int m){
        vector<bitset<INF>> dp(h+1);
        dp[h].set(m);
        int ans = 0;
        rep(i,0,n){
            vector<bitset<INF>> temp(h+1);
            rep(j,v[i][0],h+1){
                temp[j-v[i][0]] |= dp[j];
            }
            rep(j,0,h+1){
                if(v[i][1] < INF){
                    temp[j] |= (dp[j] >> v[i][1]);
                }
            }
            bool f = 0;
            rep(j,0,h+1){
                if(temp[j].any()){
                    f = 1;
                    break;
                }
            }
            if(f){
                ans = i + 1;
                dp = move(temp);
            } else {
                break;
            }
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, m;
    cin>>n>>h>>m;
    vvi v(n, vi(2));
    rep(i,0,n) cin>>v[i][0]>>v[i][1];
    Kaarti ob;
    ob.method(v, n, h, m);
    return 0;
}