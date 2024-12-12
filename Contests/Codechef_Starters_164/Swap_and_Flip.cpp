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
    void method(string& s, string& t, int n){
        int a = 0, b = 0, c = 0, d = 0;
        rep(i,0,n){
            if(s[i] == '0') a++;
            else b++;
            if(t[i] == '0') c++;
            else d++;
        }
        while(a >= 2){
            a -= 2;
            b += 2;
        }
        if(a == c && b == d){
            cout<<"YES"<<endl;
            return;
        }
        while(c >= 2){
            c -= 2;
            d += 2;
        }
        if(a == c && b == d){
            cout<<"YES"<<endl;
            return;
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
        string a,b;
        cin>>a>>b;
        Kaarti *ob = new Kaarti;
        ob->method(a, b, n);
    }
    return 0;
}