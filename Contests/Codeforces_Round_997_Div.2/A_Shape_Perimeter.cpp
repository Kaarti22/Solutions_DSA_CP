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
        int x = v[0][0], y = v[0][1];
        ans += (4 * m);
        pair<int, int>top = {x + m, y + m};
        rep(i,1,n){
            x += v[i][0], y += v[i][1];
            int diffx = top.first - x, diffy = top.second - y;
            ans -= (2 * (diffx + diffy));
            ans += (4 * m);
            top = {x + m, y + m};
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m;
        cin>>n>>m;
        vvi v(n, vi(2));
        rep(i,0,n){
            cin>>v[i][0]>>v[i][1];
        }
        Kaarti *ob = new Kaarti;
        ob->method(v, n, m);
    }
    return 0;
}