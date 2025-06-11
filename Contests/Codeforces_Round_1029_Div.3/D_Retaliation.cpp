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
        int d = n * n - 1;
        int x = n * v[n-1] - v[0];
        int y = n * v[0] - v[n-1];
        if(x < 0 || y < 0 || x % d != 0 || y % d != 0) {
            cout<<"NO"<<endl;
            return;
        }
        x /= d;
        y /= d;
        rep(i,0,n){
            if(v[i] != x * (i + 1) + y * (n - (i + 1) + 1)){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
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
        vi v(n);
        inpvec(v, n);
        Kaarti ob;
        ob.method(v, n);
    }
    return 0;
}