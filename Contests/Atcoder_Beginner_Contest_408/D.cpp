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
    void method(string& s, int n){
        int ones = 0;
        rep(i,0,n){
            if(s[i] == '1') ones++;
        }
        if(ones == 0){
            cout<<0<<endl;
            return;
        }
        vi p(n+1, 0);
        rep(i,1,n+1){
            p[i] = p[i-1] + (s[i-1] == '1' ? 1 : 0);
        }
        vi b(n+1);
        rep(i,0,n+1){
            b[i] = i - 2 * p[i];
        }
        int ans = ones;
        int maxi = b[0];
        rep(i,0,n){
            if(b[i] > maxi){
                maxi = b[i];
            }
            int curr = ones + b[i+1] - maxi;
            if(curr < ans){
                ans = curr;
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        Kaarti ob;
        ob.method(s, n);
    }
    return 0;
}