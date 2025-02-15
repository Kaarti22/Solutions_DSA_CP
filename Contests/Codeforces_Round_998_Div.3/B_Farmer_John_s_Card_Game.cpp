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
        for(auto& it: v){
            sort(all(it));
        }
        map<vector<int>, int>mp;
        rep(i,0,n){
            mp[v[i]] = i + 1;
        }
        sort(all(v));
        int prev = -1;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(v[i][j] < prev){
                cout<<-1<<endl;
                return;
            }
            prev = v[i][j];
            i++;
            if(i == n){
                i = 0;
                j++;
            }
        }
        for(auto it: v){
            cout<<mp[it]<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m;
        cin>>n>>m;
        vvi v(n, vi(m));
        rep(i,0,n){
            rep(j,0,m) cin>>v[i][j];
        }
        Kaarti *ob = new Kaarti;
        ob->method(v, n, m);
    }
    return 0;
}