#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 998244353
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
    int check(int a, int b){
        int ans = 1;
        while(b > 0){
            if(b & 1){
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }

public:
    void method(int n){
        if(n == 1){
            cout<<1<<endl;
            return;
        }
        if(n == 2){
            cout<<3<<endl;
            return;
        }
        if(n & 1){
            cout<<(check(2, n) - 1) % MOD;
        } else {
            cout<<3 * check(2, n-2) % MOD; 
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        Kaarti *ob = new Kaarti;
        ob->method(n);
    }
    return 0;
}