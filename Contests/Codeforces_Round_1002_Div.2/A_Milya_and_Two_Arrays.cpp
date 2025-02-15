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
    void method(vi &a, vi& b, int n){
        vi vis(n, 0);
        set<int>sum;
        int c = 0;
        rep(i,0,n){
            rep(j,0,n){
                int val = b[i] + a[j];
                if(sum.find(val) == sum.end() && vis[j] == 0){
                    sum.insert(val);
                    vis[j] = 1;
                    c++;
                }
                if(c == 3){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
        cout<<"NO"<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        vi a(n), b(n);
        inpvec(a, n);
        inpvec(b, n);
        Kaarti *ob = new Kaarti;
        ob->method(a, b, n);
    }
    return 0;
}