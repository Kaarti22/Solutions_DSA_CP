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
    void method(vi &v, int n){
        vi a(n), b(n);
        rep(i,0,n){
            if(i == 0){
                a[i] = max(0LL, v[i]);
            } else {
                a[i] = a[i-1] + max(0LL, v[i]);
            }
        }
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                b[i] = max(0LL, -v[i]);
            } else {
                b[i] = b[i+1] + max(0LL, -v[i]);
            }
        }
        int ans = 0;
        rep(i,0,n){
            ans = max(ans, a[i] + (i+1 < n ? b[i+1] : 0));
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        vi v(n);
        inpvec(v, n);
        Kaarti *ob = new Kaarti;
        ob->method(v, n);
    }
    return 0;
}