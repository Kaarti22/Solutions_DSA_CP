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
    void method(vi& a, vi& b, int n, int m){
        vi p(n, 0), s(n, 0);
        int j = 0;
        rep(i,0,n){
            if(j >= m){
                if(i > 0){
                    rep(k,i,n){
                        p[k] = p[k-1];
                    }
                } else {
                    rep(k,0,n){
                        p[k] = 0;
                    }
                }
                break;
            }
            if(a[i] >= b[j]){
                if(i == 0) p[i] = 1;
                else p[i] = p[i-1] + 1;
                j++;
            } else {
                if(i == 0) p[i] = 0;
                else p[i] = p[i-1];
            }
        }
        j = m - 1;
        for(int i=n-1; i>=0; i--){
            if(j < 0){
                if(i < n-1){
                    for(int k=i; k>=0; k--){
                        s[k] = s[k+1];
                    }
                } else {
                    for(int k=n-1; k>=0; k--){
                        s[k] = 0;
                    }
                }
                break;
            }
            if(a[i] >= b[j]){
                if(i == n-1) s[i] = 1;
                else s[i] = s[i+1] + 1;
                j--;
            } else {
                if(i == n-1) s[i] = 0;
                else s[i] = s[i+1];
            }
        }
        int ans = LLONG_MAX;
        rep(i,0,n){
            if(i == 0){
                if(s[i] == m){
                    cout<<0<<endl;
                    return;
                } else if(s[i] == m-1){
                    ans = min(ans, b[0]);
                }
            } else if(i == n-1){
                if(p[i] == m){
                    cout<<0<<endl;
                    return;
                } else if(p[i] == m-1){
                    ans = min(ans, b[m-1]);
                }
            } else {
                int sum = p[i] + s[i+1];
                if(sum == m){
                    cout<<0<<endl;
                    return;
                } else if(sum == m-1){
                    ans = min(ans, b[p[i]]);
                }
            }
        }
        if(p[n-1] == m-1){
            ans = min(ans, b[m-1]);
        }
        if(s[0] == m-1){
            ans = min(ans, b[0]);
        }
        if(ans != LLONG_MAX){
            cout<<ans<<endl;
        } else {
            if(p[n-1] >= m){
                cout<<0<<endl;
            } else {
                cout<<-1<<endl;
            }
        }
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m;
        cin>>n>>m;
        vi a(n), b(m);
        inpvec(a, n);
        inpvec(b, m);
        Kaarti *ob = new Kaarti;
        ob->method(a, b, n, m);
    }
    return 0;
}