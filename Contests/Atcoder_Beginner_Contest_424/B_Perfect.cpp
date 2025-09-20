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
    void method(vvi& v, int n, int m, int k){
        vi ans;
        vi people(n+1, 0);
        for(auto it: v){
            people[it[0]]++;
            if(people[it[0]] == m){
                ans.pb(it[0]);
            }
        }
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    int n, m, k;
    cin>>n>>m>>k;
    vvi v(k, vi(2));
    rep(i,0,k){
        cin>>v[i][0]>>v[i][1];
    }
    Kaarti ob;
    ob.method(v, n, m, k);
    return 0;
}