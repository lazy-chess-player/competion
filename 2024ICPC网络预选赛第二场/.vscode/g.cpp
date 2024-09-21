#include <vector>
#include <iostream>
using namespace std;

using ll = long long;

const ll mod = 998244353;

ll qmi(ll x, ll k, ll p = mod)
{
    x %= mod;
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll a0, a1, a2, b;
    cin >> a0 >> a1 >> b;
    a2 = b - a0 - a1;
    ll p0 = a0 * qmi(b, mod - 2, mod);
    ll p1 = a1 * qmi(b, mod - 2, mod);
    ll q = a0 * qmi((b - a2), mod - 2, mod) % mod;
    ll ans = 0;
    ll res = 1;
    while (1)
    {
        if (x < y)
        {
            ll d = y - x;
            ll cnt = (d + x - 1) / x;
            res = res * qmi(q, cnt, mod) % mod;
            y -= cnt * x;
        }
        else if (x == y)
        {
            ans = (ans + res * q % mod) % mod;
            break;
        }
        else
        {
            ll d = x - y;
            ll cnt = (d + y - 1) / y;
            ans = (ans + res * cnt)
        }
    }
    cout << ans << endl;
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