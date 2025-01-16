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
    void method(vi& a, vi& b, int n){
        vi vis(n, 0);
        while(1){
            int ind = -1;
            rep(i,0,n){
                if(a[i] < b[i]){
                    ind = i;
                    break;
                }
            }
            if(ind == -1){
                cout<<"YES"<<endl;
                return;
            }
            if(vis[ind] == 1){
                cout<<"NO"<<endl;
                return;
            }
            vis[ind] = 1;
            int diff = b[ind] - a[ind];
            int mini = INT_MAX;
            rep(i,0,n){
                if(i == ind) continue;
                mini = min(mini, a[i]);
            }
            if(mini < diff){
                cout<<"NO"<<endl;
                return;
            }
            rep(i,0,n){
                if(i == ind) a[i] += diff;
                else a[i] -= diff;
            }
        }
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