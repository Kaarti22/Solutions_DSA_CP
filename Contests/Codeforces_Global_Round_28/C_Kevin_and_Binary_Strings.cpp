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
        int ind = -1;
        rep(i,0,n){
            if(s[i] == '0'){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            cout<<"1 "<<n<<" 1 1"<<endl;
            return;
        }
        string t = "";
        rep(i,ind,n){
            if(s[i] == '1'){
                t += "0";
                if(s.find(t) == string::npos){
                    t.pop_back();
                    break;
                }
            } else {
                t += "1";
                if(s.find(t) == string::npos){
                    t.pop_back();
                    break;
                }
            }
        }
        // cerr<<ind<<endl;
        // cerr<<t<<endl;
        string temp = "";
        rep(i,0,ind){
            temp += "0";
        }
        // cerr<<temp<<endl;
        string copy = temp;
        temp += t;
        // cerr<<temp<<endl;
        int rem = s.size() - temp.size();
        vector<pair<int, int>>v;
        ind = -1;
        while((ind = s.find(t, ind + 1)) != string::npos){
            int st = ind + t.size();
            int end = st + rem - 1;
            if(end >= n){
                break;
            }
            v.pb({ind, end});
            // cerr<<ind<<" "<<end<<endl;
        }
        int val = 0;
        pair<int, int>ans = {-1, -1};
        string cmp = "";
        rep(i,0,n){
            cmp += "0";
        }
        for(auto it: v){
            int st = it.first, end = it.second;
            string tt = copy;
            tt += s.substr(st, end - st + 1);
            string val = "";
            rep(i,0,n){
                if((s[i] & 1) == (tt[i] & 1)){
                    val += "0";
                } else {
                    val += "1";
                }
            }
            if(val > cmp){
                cmp = val;
                ans = {st + 1, end + 1};
            }
        }
        cout<<"1 "<<n<<" "<<ans.first<<" "<<ans.second<<endl;
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