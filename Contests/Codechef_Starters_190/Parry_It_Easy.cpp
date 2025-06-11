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
    void method(vi& a, vi& b, int n, int x){
        vi maxi(n);
        maxi[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--){
            maxi[i] = max(maxi[i+1], a[i]);
        }
        int ans = 0;
        rep(i,0,n){
            if(x >= b[i]){
                if(i + 1 >= n){
                    ans++;
                    continue;
                }
                if(x - 1 >= maxi[i+1]){
                    ans++;
                    x--;
                }
            }
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, x;
        cin>>n>>x;
        vi a(n), b(n);
        inpvec(a, n);
        inpvec(b, n);
        Kaarti ob;
        ob.method(a, b, n, x);
    }
    return 0;
}