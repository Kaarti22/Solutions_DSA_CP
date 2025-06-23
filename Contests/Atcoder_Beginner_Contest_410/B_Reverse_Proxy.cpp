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
    void method(vi& v, int n, int q){
        vi a(n + 1, 0);
        rep(i,0,q){
            if(v[i] > 0){
                a[v[i]]++;
                cout<<v[i]<<" ";
            } else {
                int ind = -1, mini = INT_MAX;
                rep(j,1,n+1){
                    if(a[j] < mini){
                        mini = a[j];
                        ind = j;
                    }
                }
                a[ind]++;
                cout<<ind<<" ";
            }
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin>>n>>q;
    vi v(q);
    inpvec(v, q);
    Kaarti ob;
    ob.method(v, n, q);
    return 0;
}