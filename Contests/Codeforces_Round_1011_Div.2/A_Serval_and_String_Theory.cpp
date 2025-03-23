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
    bool check(string s){
        string t = s;
        reverse(all(t));
        return s < t;
    }

    bool negCheck(string s){
        if (s.empty()) return true;
        char prev = s[0];
        for(auto ch : s){
            if (ch != prev) return false;
        }
        return true;
    }

    int solve(string s){
        string t = s;
        sort(all(t));
        int n = s.size();
        vector<int> p(n, 0);
        vector<vector<int>> hsh(26);
        for (int i = n - 1; i >= 0; --i){
            hsh[t[i] - 'a'].push_back(i);
        }
        rep(i,0,n){
            int c = s[i] - 'a';
            p[i] = hsh[c].back();
            hsh[c].pop_back();
        }
        vector<bool> vis(n, false);
        int ans = 0;
        rep(i,0,n){
            if (!vis[i]){
                int j = i;
                while (!vis[j]){
                    vis[j] = true;
                    j = p[j];
                }
                ans++;
            }
        }
        return n - ans;
    }

    bool check2(string s, int k){
        int n = s.size();
        rep(i,0,n){
            rep(j,i+1,n){
                string t = s;
                swap(t[i], t[j]);
                if(check(t)){
                    return true;
                }
            }
        }
        return false;
    }

public:
    void method(string& s, int n, int k){
        if(check(s)){
            cout<<"YES"<<endl;
            return;
        }
        if(negCheck(s)){
            cout<<"NO"<<endl;
            return;
        }
        if(k >= (n - 1)){
            cout<<"YES"<<endl;
            return;
        }
        int ans = solve(s);
        if (ans <= k){
            cout<<"YES"<<endl;
            return;
        }
        if (k >= 1 && check2(s, k)){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        Kaarti *ob = new Kaarti;
        ob->method(s, n, k);
    }
    return 0;
}