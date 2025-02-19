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
        int ans = 0;
        map<int, set<int>>mp;
        for(auto it: v){
            if(it[0] == it[1] || mp[it[0]].find(it[1]) != mp[it[0]].end()){
                ans++;
                continue;
            }
            mp[it[0]].insert(it[1]);
            mp[it[1]].insert(it[0]);
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    // int testcase;
    // cin>>testcase;
    // for(int t=0; t<testcase; t++){
        int n, m;
        cin>>n>>m;
        vvi v(m, vi(2));
        rep(i,0,m){
            cin>>v[i][0]>>v[i][1];
        }
        Kaarti *ob = new Kaarti;
        ob->method(v, n, m);
    // }
    return 0;
}