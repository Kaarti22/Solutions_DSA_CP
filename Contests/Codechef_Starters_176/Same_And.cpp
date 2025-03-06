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
private:
    string solve1(int n){
        string ans = "";
        while(n > 0){
            if(n & 1) ans = "1" + ans;
            else ans = "0" + ans;
            n >>= 1;
        }
        return ans;
    }

    int solve2(string s){
        int ans = 0;
        for(auto it: s){
            ans *= 2;
            if(it == '1') ans++;
        }
        return ans;
    }

public:
    void method(int n, int m){
        string s = solve1(n);
        set<int>ans;
        int size = s.size();
        while(s.size() < 64){
            s = "0" + s;
        }
        rep(i,1,64){
            string t = s;
            t[i] = '1';
            if(solve2(t) <= m) ans.insert(solve2(t));
        }
        ans.insert(n);
        if(ans.size() <= 1){
            cout<<-1<<endl;
        } else {
            cout<<ans.size()<<endl;
            for(auto it: ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m;
        cin>>n>>m;
        Kaarti *ob = new Kaarti;
        ob->method(n, m);
    }
    return 0;
}