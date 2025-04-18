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
    void solve(vi& v, int n, vector<bool>& p){
        map<int, int>m;
        map<int, int>unique;
        rep(i,0,n){
            if(m.find(v[i]) == m.end()){
                m[v[i]]++;
                unique[1]++;
            } else {
                int prev = m[v[i]];
                unique[prev]--;
                if(unique[prev] == 0) unique.erase(prev);
                m[v[i]]++;
                unique[m[v[i]]]++;
            }
            int val = (i + 1) / 2;
            auto it = unique.upper_bound(val);
            if(it == unique.end()) p[i] = 0;
            else p[i] = 1;
        }
    }

public:
    void method(vi &v, int n){
        vector<bool>p(n), s(n);
        solve(v, n, p);
        reverse(all(v));
        solve(v, n, s);
        reverse(all(s));
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