#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(int x, int y, int k) {
    int diff = abs(x - y);
    if (diff == k) {
        cout << 0 << endl;
        return;
    }
    int moves = abs(diff - k) / 2;
    if ((diff - k) % 2 == 0) {
        cout << moves << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int x, y, k;
        cin >> x >> y >> k;
        solve(x, y, k);
    }
    return 0;
}
