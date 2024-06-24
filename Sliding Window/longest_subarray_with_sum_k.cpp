/*
Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.
*/

/*
This code is only for positive numbers.
For negative numbers, use some hashmap to calculate.
*/

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
    void method(vector<ll> &v, ll n, ll k){
        ll ans = 0, sum = 0;
        ll i = 0, j = 0;
        while(j < n){
            sum += v[j];
            if(sum < k){
                j++;
            } else if(sum == k){
                ans = max(ans, j - i + 1);
                j++;
            } else {
                while(sum > k){
                    sum -= v[i];
                    i++;
                }
                if(sum == k){
                    ans = max(ans, j - i + 1);
                }
                j++;
            }
        }
        cout<<ans<<endl;
    }
};

int main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        ll n;
        cin>>n;
        vector<ll> v(n);
        rep(i,0,n) cin>>v[i];
        ll k;
        cin>>k;
        Kaarti *ob = new Kaarti;
        ob->method(v, n, k);
    }
    return 0;
}