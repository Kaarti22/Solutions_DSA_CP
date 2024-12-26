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
        int c = 0;
        rep(i,0,n){
            if(v[i] == 0) c++;
        }
        if(c == 0) cout<<1<<endl;
        else if(c == n) cout<<0<<endl;
        else {
            int i1 = -1;
            rep(i,0,n){
                if(v[i] != 0){
                    i1 = i;
                    break;
                }
            }
            int i2 = -1;
            for(int i=n-1; i>=0; i--){
                if(v[i] != 0){
                    i2 = i;
                    break;
                }
            }
            bool f = 1;
            rep(i,i1+1,i2){
                if(v[i] == 0){
                    f = 0;
                    break;
                }
            }
            if(f) cout<<1<<endl;
            else cout<<2<<endl;
        }
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