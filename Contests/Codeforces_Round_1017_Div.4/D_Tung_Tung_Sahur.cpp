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
    void method(string& a, string& b){
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] != b[j]){
                cout<<"NO"<<endl;
                return;
            }
            char ch = a[i];
            int c = 0, d = 0;
            while(i < n && a[i] == ch){
                i++;
                c++;
            }
            while(j < m && b[j] == ch){
                j++;
                d++;
            }
            if((d > 2 * c) || (d < c)){
                cout<<"NO"<<endl;
                return;
            }
        }
        if(i == n && j == m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        string a, b;
        cin>>a>>b;
        Kaarti *ob = new Kaarti;
        ob->method(a, b);
    }
    return 0;
}