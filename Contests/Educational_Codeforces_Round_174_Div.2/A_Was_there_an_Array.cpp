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
    void method(vi &v, int n){
        vi ans(n, -1);
        int c = 1;
        rep(i,0,n){
            if(v[i] == 1){
                int val = -1;
                if(ans[i-1] != -1) val = ans[i-1];
                if(ans[i] != -1) val = ans[i];
                if(ans[i+1] != -1) val = ans[i+1];
                if(val == -1){
                    ans[i-1] = c;
                    ans[i] = c;
                    ans[i+1] = c;
                    c++;
                } else {
                    ans[i-1] = val;
                    ans[i] = val;
                    ans[i+1] = val;
                }
            }
        }
        rep(i,0,n+2){
            if(ans[i] == -1){
                ans[i] = c;
                c++;
            }
        }
        rep(i,0,n){
            if(v[i] == 0){
                if(ans[i] == ans[i-1] && ans[i] == ans[i+1]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        cout<<"YES"<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        vi v(n);
        v[0] = -1;
        rep(i,1,n-1){
            cin>>v[i];
        }
        v[n-1] = -1;
        Kaarti *ob = new Kaarti;
        ob->method(v, n);
    }
    return 0;
}