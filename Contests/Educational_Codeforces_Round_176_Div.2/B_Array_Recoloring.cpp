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
    int second(vi& v, vi& vis, int n, int ans){
        while(1){
            int ind = -1;
            int maxi = -1;
            rep(i,0,n){
                if(vis[i] == 0 && v[i] > maxi){
                    ind = i;
                    maxi = v[i];
                }
            }
            if(ind == -1) break;
            if(ind == 0 || ind == n-1){
                ans += v[ind];
                break;
            }
            int i = ind - 1, j = ind + 1;
            bool a = 0;
            while(i >= 0){
                if(vis[i] == 1){
                    a = 1;
                    break;
                }
                i--;
            }
            bool b = 0;
            while(j < n){
                if(vis[j] == 1){
                    b = 1;
                    break;
                }
                j++;
            }
            if(a && b){
                ans += v[ind];
                break;
            }
            vis[ind] = 1;
        }
        return ans;
    }

    int first(vi& v, vi& vis, int n, int k, int used, int ans, int ind){
        if(used == k || ind >= n){
            return second(v, vis, n, ans);
        }
        if(ind > k - used){
            vis[ind] = 1;
            return first(v, vis, n, k, used + 1, ans + v[ind], ind + 1);
        }
        vis[ind] = 1;
        int a = first(v, vis, n, k, used + 1, ans + v[ind], ind + 1);
        vis[ind] = 0;
        int b = first(v, vis, n, k, used, ans, ind + 1);
        return max(a, b);
    }

public:
    void method(vi &v, int n, int k){
        int ans = 0;
        vi vis(n, 0);
        int used = 0;
        cout<<first(v, vis, n, k, used, ans, 0)<<endl;
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