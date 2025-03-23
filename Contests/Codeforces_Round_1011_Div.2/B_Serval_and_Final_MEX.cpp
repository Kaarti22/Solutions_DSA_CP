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
        int first = -1;
        rep(i,0,n){
            if(v[i] == 0){
                first = i;
                break;
            }
        }
        if(first == -1){
            cout<<"1"<<endl;
            cout<<"1 "<<n<<endl;
            return;
        }
        int last = -1;
        for(int i=n-1; i>=0; i--){
            if(v[i] == 0){
                last = i;
                break;
            }
        }
        if(first == 0 && last == n-1){
            cout<<"3"<<endl;
            cout<<"1 2"<<endl;
            cout<<"2 "<<n-1<<endl;
            cout<<"1 2"<<endl;
            return;
        } else {
            cout<<"2"<<endl;
            if(first == last){
                if(first - 1 >= 0){
                    cout<<first<<" "<<first+1<<endl;
                } else {
                    cout<<first+1<<" "<<first+2<<endl;
                }
                cout<<"1 "<<n-1<<endl;
                return;
            } else {
                cout<<first+1<<" "<<last+1<<endl;
                int rem = n - (last - first + 1) + 1;
                cout<<"1 "<<rem<<endl;
                return;
            }
        }
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