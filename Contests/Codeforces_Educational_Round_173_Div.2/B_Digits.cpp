#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

void inparr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void disarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void inpvec(vi &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void disvec(vi v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int madd(int a, int b)
{
    return (a + b) % MOD;
}

int msub(int a, int b)
{
    return (((a - b) % MOD) + MOD) % MOD;
}

int mmul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

class Kaarti
{
private:
    map<int, int> m = {
        {1, 1},
        {2, 2},
        {3, 6},
        {4, 24},
        {5, 120},
        {6, 720},
        {7, 5040},
        {8, 40320},
    };

    bool c3(int n, int d)
    {
        if (d == 3 || d == 6 || d == 9)
            return true;
        if (n >= 3)
            return true;
        return false;
    }

    bool check(int n)
    {
        if (n >= 9)
            return true;
        if (m[n] % 9 == 0)
            return true;
        return false;
    }

    bool c7(int n, int d)
    {
        if (d % 7 == 0)
            return true;
        if (n >= 7)
            return true;
        return false;
    }

    bool c9(int n, int d)
    {
        if (d == 9)
            return true;
        if (n >= 9)
            return true;
        if ((m[n] * d) % 9 == 0)
            return true;
        return false;
    }

public:
    void method(int n, int d)
    {
        cout << 1 << " ";
        if (c3(n, d))
            cout << 3 << " ";
        if (d == 5)
            cout << 5 << " ";
        if (c7(n, d))
            cout << 7 << " ";
        if (c9(n, d))
            cout << 9 << " ";
        cout << endl;
    }
};

int32_t main()
{
    int testcase;
    cin >> testcase;
    for (int t = 0; t < testcase; t++)
    {
        int n, d;
        cin >> n >> d;
        Kaarti *ob = new Kaarti;
        ob->method(n, d);
    }
    return 0;
}