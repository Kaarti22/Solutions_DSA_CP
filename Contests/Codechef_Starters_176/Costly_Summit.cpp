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
    int solve(vi& v, int c, int ans, int trans, int ind){
        if(ind == 5) return ans;
        if(v[ind] == 0) return solve(v, c, ans, trans, ind + 1);
        int a = c;
        int b = ((trans + v[ind]) * (trans + v[ind] + 1))/2 - (trans * (trans + 1))/2;
        return min(solve(v, c, ans + a, trans, ind + 1), solve(v, c, ans + b, trans + v[ind], ind + 1));
    }

public:
    void method(string& s, int n, int c){
        vi v(5, 0);
        for(auto it: s){
            v[it - 'A']++;
        }
        cout<<solve(v, c, 0LL, 0LL, 0)<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, c;
        cin>>n>>c;
        string s;
        cin>>s;
        Kaarti *ob = new Kaarti;
        ob->method(s, n, c);
    }
    return 0;
}