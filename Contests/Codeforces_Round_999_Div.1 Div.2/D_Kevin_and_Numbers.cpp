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
    void method(vi& x, vi& y, int n, int m){
        // cerr<<1<<endl;
        multiset<int>a, b;
        for(auto it: x) a.insert(it);
        for(auto it: y) b.insert(it);
        auto i = a.begin();
        auto j = b.begin();
        while(i != a.end() && j != b.end()){
            if(*i == *j){
                i++;
                j++;
                continue;
            }
            // cerr<<"f: "<<*i<<endl;
            int val1 = *i;
            i = a.erase(i);
            // cerr<<"s: "<<*i<<endl;
            if(i == a.end()){
                cout<<"No"<<endl;
                return;
            }
            int val2 = *i;
            if((val1 == val2) && ((val1 + val2) != *j) && (a.find(val1 + 1) != a.end()) && (*j == (val1 + val1 + 1))){
                auto ind = a.find(val1 + 1);
                a.erase(ind);
                a.insert(val1 + val1 + 1);
                // cerr<<"n: "<<*i<<endl;
                continue;
            }
            i = a.erase(i);
            if(val2 - val1 > 1){
                cout<<"No"<<endl;
                return;
            }
            int sum = val1 + val2;
            if(*i >= sum){
                i = a.insert(val1 + val2);
            } else {
                a.insert(val1 + val2);
            }
            // cerr<<"n: "<<*i<<endl;
        }
        // for(auto it: a){
        //     cerr<<it<<" ";
        // }
        // cerr<<endl;
        // for(auto it: b){
        //     cerr<<it<<" ";
        // }
        // cerr<<endl;
        if(a == b){
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m;
        cin>>n>>m;
        vi a(n);
        inpvec(a, n);
        vi b(m);
        inpvec(b, m);
        Kaarti *ob = new Kaarti;
        ob->method(a, b, n, m);
    }
    return 0;
}