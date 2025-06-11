#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vi a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        // 1) Precompute last occurrence of each value
        vi last(n+1, 0);
        for(int i = 1; i <= n; i++){
            last[a[i]] = i;
        }

        // 2) DP array: dp[i] = max #segments in suffix starting at i
        //    dp[n+1] = 0
        vi dp(n+2, 0);

        // 3) Fill dp from right to left
        for(int i = n; i >= 1; i--){
            int min_last = INF;
            int best = 1;  
            // try to end the first segment at j, then add dp[j+1]
            for(int j = i; j <= n; j++){
                min_last = min(min_last, last[a[j]]);
                // if every a[k] in [i..j] has last[a[k]] > j,
                // we can make a cool cut here
                if (min_last > j) {
                    best = max(best, 1 + dp[j+1]);
                } else {
                    // as soon as min_last <= j, no longer valid to extend
                    break;
                }
            }
            dp[i] = best;
        }

        // 4) answer for this test is dp[1]
        cout << dp[1] << "\n";
    }

    return 0;
}
