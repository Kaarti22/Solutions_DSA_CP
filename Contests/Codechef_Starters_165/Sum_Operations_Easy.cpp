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
    void method(vi &v, int n){
        int ans = 0;
        int sum = accumulate(all(v), 0LL);
        priority_queue<pair<int, int>, vector<pair<int, int>>>pq;
        set<int>s;
        rep(i,0,n){
            pq.push({abs(v[i]), i});
            if(v[i] != 0) s.insert(i);
        }
        while(s.size() > 0){
            while(s.find(pq.top().second) == s.end()){
                pq.pop();
            }
            int val = min(n, abs(sum)) - pq.top().first;
            
            auto ub = s.upper_bound(val);
            if(ub == s.begin()){
                cout<<-1<<endl;
                return;
            }
            ub--;
            int ind = (int)*ub;
            ans += v[ind];
            s.erase(ind);
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n;
        cin>>n;
        vi v(n);
        inpvec(v, n);
        Kaarti *ob = new Kaarti;
        ob->method(v, n);
    }
    return 0;
}