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
    void method(vi& a, vi& b, int n, int k){
        int sum = -1;
        rep(i,0,n){
            if(b[i] == -1) continue;
            int val = a[i] + b[i];
            if(sum == -1){
                sum = val;
            } else {
                if(sum != val){
                    cout<<0<<endl;
                    return;
                }
            }
        }
        if(sum != -1){
            rep(i,0,n){
                if(b[i] == -1){
                    b[i] = sum - a[i];
                    if(b[i] > k || b[i] < 0){
                        cout<<0<<endl;
                        return;
                    }
                }
            }
            cout<<1<<endl;
        } else {
            int mini = *min_element(all(a));
            int maxi = *max_element(all(a));
            cout<<k + mini - maxi + 1<<endl;
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, k;
        cin>>n>>k;
        vi a(n), b(n);
        inpvec(a, n);
        inpvec(b, n);
        Kaarti *ob = new Kaarti;
        ob->method(a, b, n, k);
    }
    return 0;
}