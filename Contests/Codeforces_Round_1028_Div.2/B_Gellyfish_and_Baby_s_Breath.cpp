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

const int mod = 998244353;
const int MAX_EXP = 100000;
vi dp(MAX_EXP + 1);

void precompute(){
    dp[0] = 1;
    rep(i,1,MAX_EXP+1){
        dp[i] = (dp[i-1] * 2) % mod;
    }
}

class Kaarti{
public:
    void method(vi& a, vi& b, int n){
        vi ans(n);
        int maxi_a = a[0], maxi_a_ind = 0;
        int maxi_b = b[0], maxi_b_ind = 0;
        int a0 = max(a[0], b[0]);
        int b0 = min(a[0], b[0]);
        ans[0] = (dp[a0] + dp[b0]) % mod;
        rep(i,1,n){
            if(a[i] > maxi_a){
                maxi_a = a[i];
                maxi_a_ind = i;
            }
            if(b[i] > maxi_b){
                maxi_b = b[i];
                maxi_b_ind = i;
            }
            int ind1 = i - maxi_a_ind;
            int x1 = maxi_a;
            int y1 = b[ind1];
            int ind2 = i - maxi_b_ind;
            int x2 = a[ind2];
            int y2 = maxi_b;
            int a1 = max(x1, y1);
            int b1 = min(x1, y1);
            int a2 = max(x2, y2);
            int b2 = min(x2, y2);
            if(a1 > a2){
                ans[i] = (dp[a1] + dp[b1]) % mod;
            } else if(a1 < a2){
                ans[i] = (dp[a2] + dp[b2]) % mod;
            } else {
                if(b1 >= b2){
                    ans[i] = (dp[a1] + dp[b1]) % mod;
                } else {
                    ans[i] = (dp[a2] + dp[b2]) % mod;
                }
            }
        }
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        vi a(n), b(n);
        inpvec(a, n);
        inpvec(b, n);
        Kaarti ob;
        ob.method(a, b, n);
    }
    return 0;
}