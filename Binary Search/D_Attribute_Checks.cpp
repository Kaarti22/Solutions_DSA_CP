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

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

class Kaarti{
private:
    // DP Table: Memoization table to store the results of subproblems
    vector<vector<vector<int>>> dp;
    
    int solve(int str, int itl, int m, vi& v, int ind) {
        // Base case: If we've processed all records, return 0 checks passed.
        if (ind >= v.size()) return 0;
        
        // If already computed, return the cached value
        if (dp[str][itl][m] != -1) return dp[str][itl][m];
        
        int ans = 0;
        
        // Case 1: Attribute check (either intelligence or strength)
        if (v[ind] > 0) {  // Intelligence check
            if (itl >= v[ind]) {
                ans = 1 + solve(str, itl, m, v, ind + 1);
            } else {
                ans = solve(str, itl, m, v, ind + 1);
            }
        } else if (v[ind] < 0) {  // Strength check
            if (str >= abs(v[ind])) {
                ans = 1 + solve(str, itl, m, v, ind + 1);
            } else {
                ans = solve(str, itl, m, v, ind + 1);
            }
        } else {  // Case 2: Distribute a point (v[ind] == 0)
            if (m > 0) {
                // Two options: assign the point to strength or intelligence
                int option1 = solve(str + 1, itl, m - 1, v, ind + 1);
                int option2 = solve(str, itl + 1, m - 1, v, ind + 1);
                ans = max(option1, option2);
            } else {
                ans = solve(str, itl, m, v, ind + 1);  // No points to assign, just move on
            }
        }
        
        // Store the result in the DP table and return it
        return dp[str][itl][m] = ans;
    }

public:
    void method(vi &v, int m) {
        // Estimate the maximum possible strength and intelligence levels to size the DP table
        int maxStr = m;  // Maximum strength level will be at most 'm' if all points are assigned to strength
        int maxItl = m;  // Maximum intelligence level will be at most 'm' if all points are assigned to intelligence
        
        // Initialize DP table with -1 (indicating uncomputed states)
        dp = vector<vector<vector<int>>>(maxStr + 1, vector<vector<int>>(maxItl + 1, vector<int>(m + 1, -1)));
        
        // Initial strength and intelligence are 0, and m points are available to distribute
        int str = 0, itl = 0;
        cout << solve(str, itl, m, v, 0) << endl;
    }
};

int32_t main() {
    int m, n;
    cin >> m >> n;
    vi v(m);
    inpvec(v, m);
    Kaarti *ob = new Kaarti;
    ob->method(v, m);
    return 0;
}
