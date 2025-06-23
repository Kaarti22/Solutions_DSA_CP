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
    void method(vi& v, int n){
        int ans = 0;
        rep(k,2,n-1){
            int val;
            if(v[n-1] >= 2 * v[k]){
                val = v[n-1] - v[k];
            } else {
                val = v[k];
            }
            int j = k - 1;
            rep(i,0,k){
                while(j > i && v[i] + v[j] > val){
                    j--;
                }
                int mid = (j > i) ? j : i;
                ans += (k - 1 - mid);
            }
        }
        int target = v[n-1];
        int j = n - 2;
        rep(i,0,n-1){
            while(j > i && v[i] + v[j] > target){
                j--;
            }
            int mid = (j > i) ? j : i;
            ans += (n - 2 - mid);
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        vi v(n);
        inpvec(v, n);
        Kaarti ob;
        ob.method(v, n);
    }
    return 0;
}