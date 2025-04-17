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
    void method(vi &v, int n, int k, int d){
        vi next(n, 1);
        int total = 0;
        rep(i,1,d+1){
            vi a;
            rep(j,0,n){
                if(next[j] <= i){
                    a.pb(j);
                }
            }
            sort(all(a), [&](int x, int y){
                return v[x] < v[y];
            });
            int p = max(static_cast<int>(a.size()) - k, 0LL);
            p = min(p, static_cast<int>(a.size()));
            rep(j,0,p){
                int ind = a[j];
                total++;
                next[ind] = i + v[ind];
            }
        }
        cout<<total<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, d, k;
        cin>>n>>k>>d;
        vi v(n);
        inpvec(v, n);
        Kaarti *ob = new Kaarti;
        ob->method(v, n, k, d);
    }
    return 0;
}