#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> impressions(n);

        for (int i = 0; i < n; ++i) {
            cin >> impressions[i].first >> impressions[i].second;
        }

        string result(n, '0');
        set<int> possible_values;

        for (int i = 1; i <= 2 * n; ++i) {
            possible_values.insert(i);
        }

        for (int i = 0; i < n; ++i) {
            int l = impressions[i].first;
            int r = impressions[i].second;
            auto it = possible_values.lower_bound(l);

            if (it != possible_values.end() && *it <= r) {
                result[i] = '1';
                possible_values.erase(it);
            }
        }

        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
