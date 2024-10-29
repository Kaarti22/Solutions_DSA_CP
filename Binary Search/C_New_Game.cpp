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
    void method(vi &a, int n, int k){
        map<int, int>m;
        for(auto it: a){
            m[it]++;
        }
        vector<pair<int, int>> v;
        for(auto it: m){
            v.pb({it.first, it.second});
        }
        int len = v.size();
        int ans = v[0].second, temp = v[0].second;
        int i = 0, j = 1, count = 1;
        while(j < len){
            if(count == k){
                temp -= v[i].second;
                count--;
                i++;
            }
            if(v[j].first == v[j-1].first + 1){
                count++;
                temp += v[j].second;
            } else {
                temp = v[j].second;
                i = j;
                count = 1;
            }
            ans = max(ans, temp);
            j++;
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, k;
        cin>>n>>k;
        vi v(n);
        inpvec(v, n);
        Kaarti *ob = new Kaarti;
        ob->method(v, n, k);
    }
    return 0;
}