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
    int fun(int a, int b, int mod) {
        int ans = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return ans;
    }

    bool check(int n){
        if (n <= 1) return 0;
        if (n <= 3) return 1;
        if (n % 2 == 0) return 0;
        int d = n - 1;
        int s = 0;
        while (d % 2 == 0) {
            d /= 2;
            s++;
        }
        vi b = {2, 3, 5, 7, 11, 13};
        for (auto a : b) {
            if (a >= n) continue;
            int x = fun(a, d, n);
            if (x == 1 || x == n - 1) continue;
            bool f = 0;
            rep(j,0,s-1){
                x = (x * x) % n;
                if (x == n - 1) {
                    f = 1;
                    break;
                }
            }
            if (!f) {
                return 0;
            }
        }
        return 1;
    }

public:
    void method(int n, int k){
        if (k != 1) {
            if (k == 2 && n == 1) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        } else {
            if (check(n)){
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, k;
        cin>>n>>k;
        Kaarti *ob = new Kaarti;
        ob->method(n, k);
    }
    return 0;
}