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
    void method(vi& v, int n){
        unordered_map<int, vi> m;
        rep(i,0,n){
            m[v[i]].pb(i);
        }
        int ans = 1;
        rep(i,0,n-1){
            if(i > 0 && v[i] == v[i-1]) continue;
            int count = 0;
            int size = m[v[i]].size();
            auto lb = lower_bound(m[v[i]].begin(), m[v[i]].end(), i);
            int ind = lb - m[v[i]].begin();
            count += (size - ind - 1);
            int len = n - i - 1;
            ans += (len - count);
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi v(n);
    inpvec(v, n);
    Kaarti ob;
    ob.method(v, n);
    return 0;
}