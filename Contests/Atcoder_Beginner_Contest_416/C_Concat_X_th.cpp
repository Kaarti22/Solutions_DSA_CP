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
    void solve(int n, int k, vector<string>& v, vector<string>& ans, vi& curr){
        if(curr.size() == k){
            string s = "";
            for(auto it: curr){
                s += v[it];
            }
            ans.pb(s);
            return;
        }
        rep(i,0,n){
            curr.pb(i);
            solve(n, k, v, ans, curr);
            curr.pop_back();
        }
    }

public:
    void method(vector<string>& v, int n, int k, int x){
        vector<string> ans;
        vi curr;
        solve(n, k, v, ans, curr);
        sort(all(ans));
        cout<<ans[x-1]<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x;
    cin>>n>>k>>x;
    vector<string> v(n);
    rep(i,0,n) cin>>v[i];
    Kaarti ob;
    ob.method(v, n, k, x);
    return 0;
}