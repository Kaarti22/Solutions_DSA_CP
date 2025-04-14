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
    void method(vvi &v, int n){
        set<int>s;
        rep(i,1,2*n+1){
            s.insert(i);
        }
        vi ans(2 * n);
        rep(i,0,n){
            rep(j,0,n){
                ans[i+j+1] = v[i][j];
                s.erase(v[i][j]);
            }
        }
        for(auto& it: ans){
            if(it == 0){
                it = *s.begin();
                break;
            }
        }
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        vvi v(n, vi(n));
        rep(i,0,n){
            rep(j,0,n){
                cin>>v[i][j];
            }
        }
        Kaarti *ob = new Kaarti;
        ob->method(v, n);
    }
    return 0;
}