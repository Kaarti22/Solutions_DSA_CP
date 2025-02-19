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
    bool check(set<pair<int, int>>& s) {
        for (auto it : s) {
            int x = it.first, y = it.second;
            if (s.count({x+1, y})) return true;
            if (s.count({x-1, y})) return true;
            if (s.count({x, y+1})) return true;
            if (s.count({x, y-1})) return true;
        }
        return false;
    }

public:
    void method(vvi& v, int n, int m){
        map<int, set<pair<int, int>>>mp;
        rep(i,0,n){
            rep(j,0,m){
                mp[v[i][j]].insert({i, j});
            }
        }
        vi ans;
        for(auto it: mp){
            if(it.second.size() <= 1){
                ans.pb(1);
            } else {
                if(check(it.second)){
                    ans.pb(2);
                } else {
                    ans.pb(1);
                }
            }
        }
        sort(ans.rbegin(), ans.rend());
        int sum = accumulate(all(ans), 0LL);
        cout<<sum - (ans.empty() ? 0 : ans[0])<<endl;
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
            rep(j,0,m){
                cin>>v[i][j];
            }
        }
        Kaarti *ob = new Kaarti;
        ob->method(v, n, m);
    }
    return 0;
}