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
    void method(vi& a, vi& b, int n){
        vvi ans;
        rep(i,0,n){
            if(a[i] > b[i]){
                swap(a[i], b[i]);
                ans.pb({3, i+1});
            }
        }
        rep(i,0,n){
            rep(j,1,n-i){
                if(a[j-1] > a[j]){
                    swap(a[j-1], a[j]);
                    swap(b[j-1], b[j]);
                    ans.pb({1, j});
                    ans.pb({2, j});
                }
            }
        }
        rep(i,0,n){
            rep(j,1,n-i){
                if(b[j-1] > b[j]){
                    swap(b[j-1], b[j]);
                    ans.pb({2, j});
                }
            }
        }
        cout<<ans.size()<<endl;
        for(auto it: ans){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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