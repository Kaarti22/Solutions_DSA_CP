/*
Link: https://www.spoj.com/problems/AGGRCOW/

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

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
    bool canPlaceCows(vi& v, int n, int c, int dist){
        int count = 1;
        int last = v[0];
        rep(i,1,n){
            if(v[i] - last >= dist){
                count++;
                last = v[i];
            }
        }
        return count >= c;
    }

public:
    void method(vi &v, int n, int c){
        sort(all(v));
        int low = 1, high = v[n-1] - v[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canPlaceCows(v, n, c, mid)){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout<<high<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, c;
        cin>>n>>c;
        vi v(n);
        inpvec(v, n);
        Kaarti *ob = new Kaarti;
        ob->method(v, n, c);
    }
    return 0;
}