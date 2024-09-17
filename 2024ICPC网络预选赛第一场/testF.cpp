#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define int long long
#define ll long long
#define vv vector

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : abs(a);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
ll qmi(ll x, ll y, ll mod)
{
    x %= mod;
    ll s = 1;
    while (y)
    {
        if (y & 1)
        {
            s *= x;
            s %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return s % mod;
}

void solve()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    vector<int> p;
    p.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mx)
            p.push_back(i);
    }
    p.push_back(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int v = a[i];
        if (v == mx)
            continue;
    }
}
signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}