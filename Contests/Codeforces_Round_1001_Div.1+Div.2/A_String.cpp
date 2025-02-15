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
    void method(string& s){
        int n = s.size();
        int ans = 0;
        while(1){
            int last = -1;
            for(int i=n-1; i>=0; i--){
                if(s[i] == '1'){
                    last = i;
                    break;
                }
            }
            if(last == -1) break;
            ans++;
            int i = 0;
            while(i <= last){
                int j = i;
                while(j <= last){
                    if(s[j] == '1'){
                        s[j] = '0';
                        break;
                    }
                    j++;
                }
                if(j == last) break;
                j++;
                while(j < last){
                    if(s[j] == '0'){
                        s[j] = '1';
                        break;
                    }
                    j++;
                }
                i = j+1;
            }
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        string s;
        cin>>s;
        Kaarti *ob = new Kaarti;
        ob->method(s);
    }
    return 0;
}