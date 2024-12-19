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
        int ind = -1;
        rep(i,0,n-1){
            if(s[i] == s[i+1]){
                ind = i + 1;
                break;
            }
        }
        if(ind == -1){
            cout<<"Yes"<<endl;
            return;
        }
        int ind1 = -1;
        for(int j=n-2; j>=0; j--){
            if(s[j] == s[j+1]){
                ind1 = j;
                break;
            }
        }
        if(ind < ind1){
            reverse(s.begin() + ind, s.begin() + ind1 + 1);
        } else {
            reverse(s.begin() + ind, s.end());
        }
        bool f = 1;
        rep(i,0,n-1){
            if(s[i] == s[i+1]){
                f = 0;
                break;
            }
        }
        if(f){
            cout<<"Yes"<<endl;
            return;
        }
        reverse(s.begin(), s.begin() + ind);
        rep(i,0,n-1){
            if(s[i] == s[i+1]){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
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