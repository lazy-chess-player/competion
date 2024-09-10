#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <random>
#include <iomanip>
#include <time.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define ld long double
#define pii pair<long, long>
#define vv vector
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : abs(a);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
const ll mod = 998244353;
ll qmi(ll x, ll k, ll p = mod)
{
    ll res = 1;
    x %= p;
    while (k)
    {
        if (k & 1)
            res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res;
}

const int N = 30;

ll fact[N], infact[N];

void getFact()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

ll C(int a, int b)
{
    if (a < b)
        return 0;
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}
ll A(int a, int b)
{
    return fact[a] * infact[a - b] % mod;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << m + 1 << " " << m + 1 << endl;
        return;
    }
    ll maxCnt = (1ll + qmi(min(n, 26ll), m, mod)) % mod;
    vector<vector<ll>> dp(n + 1, vector<ll>(27));
    dp[1][1] = 26;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            dp[i][j] = (dp[i][j] + (j * dp[i - 1][j] % mod)) % mod;
            if (j <= i)
                dp[i][j] = (dp[i][j] + ((26 - j + 1) * dp[i - 1][j - 1] % mod)) % mod;
        }
    }
    ll e = 0;
    for (int i = 1; i <= 26; i++)
    {
        e = (e + (i * dp[n][i]) % mod) % mod;
    }
    ll t = qmi(qmi(26, n, mod), mod - 2, mod);
    ll p = qmi(e, m, mod);
    ll q = qmi(t, m, mod);
    cout << maxCnt << " " << (1ll + p * q) % mod << endl;
}
signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getFact();
    int _ = 1;
    // cin >> _;

    while (_--)
    {
        solve();
    }

    return 0;
}