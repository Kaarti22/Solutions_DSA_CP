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
    void method(string& s, int n){
        int pc = 0, sc = 0;
        for(auto it: s){
            if(it == 'p') pc++;
            else if(it == 's') sc++;
        }
        if(pc == 0 || sc == 0){
            cout<<"YES"<<endl;
            return;
        }
        int ind = -1;
        rep(i,0,n){
            if(s[i] == 'p'){
                ind = i;
                break;
            }
        }
        rep(i,ind+1,n){
            if(s[i] == 's'){
                cout<<"NO"<<endl;
                return;
            }
        }
        if(n & 1){
            cout<<"YES"<<endl;
            return;
        }
        if(s[n/2] == 'p' && s[n/2-1] == 's'){
            if(n == 2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        Kaarti *ob = new Kaarti;
        ob->method(s, n);
    }
    return 0;
}