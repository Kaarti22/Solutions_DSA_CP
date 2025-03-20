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

bool check(int n){
    if(n == 1) return false;
    for(int i=2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
}

class Kaarti {
public:
    void method(int n, int k) {
        
    }
};

const int MAXN = 1e9;
const int SQR_MAXN = 31622; // sqrt(1e9)
vector<int> small_primes; // Stores primes up to sqrt(N)

// Simple Sieve to find small primes
void simple_sieve() {
    vector<bool> is_prime(SQR_MAXN + 1, true);
    for (int i = 2; i * i <= SQR_MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= SQR_MAXN; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= SQR_MAXN; i++) {
        if (is_prime[i]) small_primes.pb(i);
    }
}

// Segmented Sieve to generate primes up to MAXN
vector<int> segmented_sieve() {
    vector<int> primes;
    int segment_size = 1e6; // Process in blocks of 10^6

    for (int low = 0; low <= MAXN; low += segment_size) {
        int high = min(low + segment_size - 1, MAXN);
        vector<bool> is_prime(high - low + 1, true);

        // Mark multiples of small primes
        for (int p : small_primes) {
            int start = max(p * p, (low + p - 1) / p * p);
            for (int j = start; j <= high; j += p)
                is_prime[j - low] = false;
        }

        // Collect primes in this segment
        for (int i = low; i <= high; i++) {
            if (is_prime[i - low] && i > 1) primes.pb(i);
        }
    }

    return primes;
}

int32_t main() {
    simple_sieve();
    vector<int>primes = segmented_sieve();
    for(auto it: primes){
        cout<<it<<" ";
    }
    cout<<endl;
    // int testcase;
    // cin >> testcase;
    // while (testcase--) {
    //     int n, k;
    //     cin >> n >> k;
    //     Kaarti ob;
    //     ob.method(n, k);
    // }
    return 0;
}
