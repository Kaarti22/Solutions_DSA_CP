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
        vi pre(n);
        bool f = 1;
        pre[0] = v[0] % 3;
        if(pre[0] == 0){
            f = 0;
        }
        rep(i,1,n){
            pre[i] = (pre[i-1] + v[i]) % 3;
            if(pre[i] == 0){
                f = 0;
            }
        }
        if(f){
            cout<<"Yes"<<endl;
            return;
        }
        vi suf(n+1, 0);
        suf[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(pre[i] != 0){
                suf[i] = suf[i+1];
            } else {
                suf[i] = 0;
            }
        }
        bool check[3] = {false};
        check[0] = 1;
        check[pre[0]] = 1;
        f = 0;
        rep(k,2,n+1){
            if(suf[k] == 1){
                if(!check[pre[k-1]]){
                    f = 1;
                    break;
                }
            }
            if(k < n) check[pre[k-1]] = 1;
        }
        if(f) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
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