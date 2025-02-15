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
    int solve(int a, int b, int c, int d, int e){
        int ans = 0;
        if(a + b == c) ans++;
        if(b + c == d) ans++;
        if(c + d == e) ans++;
        return ans;
    }

public:
    void method(int a, int b, int d, int e){
        int ans = 0;
        ans = max(ans, solve(a, b, a + b, d, e));        
        ans = max(ans, solve(a, b, d - b, d, e));        
        ans = max(ans, solve(a, b, e - d, d, e));
        cout<<ans<<endl;        
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        Kaarti *ob = new Kaarti;
        ob->method(a, b, c, d);
    }
    return 0;
}