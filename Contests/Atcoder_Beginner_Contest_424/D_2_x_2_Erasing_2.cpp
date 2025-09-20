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
    void solve(vector<string>& v, int n, int m, int sti, int stj, int curr, int& ans){
        if(curr >= ans) return;
        rep(i,sti,n-1){
            rep(j,(i == sti ? stj : 0),m-1){
                if(v[i][j] == '#' && v[i+1][j] == '#' && v[i][j+1] == '#' && v[i+1][j+1] == '#'){
                    vector<pair<int, int>> cells = {
                        {i+1, j}, {i+1, j+1}
                    };
                    for(auto it: cells){
                        v[it.first][it.second] = '.';
                        solve(v, n, m, i, j+1, curr + 1, ans);
                        v[it.first][it.second] = '#'; 
                    }
                    return;
                }
            }
        }
        ans = min(ans, curr);
    }

public:
    void method(vector<string>& v, int n, int m){
        int ans = 1e9;
        solve(v, n, m, 0, 0, 0, ans);
        cout<<ans<<endl;
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
        vector<string> v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        Kaarti ob;
        ob.method(v, n, m);
    }
    return 0;
}