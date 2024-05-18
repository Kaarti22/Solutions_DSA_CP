#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ll long long
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
    void method(int a, int b, int c){
        int ans = 0;
        int x = a, y = b, z = c;
        while(1){
            if(b > 0 && c > 0){
                ans++;
                b--;
                c--;
            } else {
                break;
            }
            if(a > b){
                swap(a, b);
            }
            if(b > c){
                swap(b, c);
            }
        }
        if(c % 2 == 0){
            cout<<ans<<endl;
        } else {
            cout<<"-1"<<endl;
        }
    }
};

int main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int a, b, c;
        cin>>a>>b>>c;
        Kaarti *ob = new Kaarti;
        ob->method(a, b, c);
    }
    return 0;
}