#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define ld long double
#define pii pair<long, long>
#define vv vector

using i128 = __int128_t;

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
    int s = 1;
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
    return s;
}

const ll mod = 998244353;
void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = '@' + s;
    t = '@' + t;
    vector<int> q(110, 0), qq(110, 0), h(110, 0), hh(110, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= 100; i++)
            qq[i] = q[i] * 2, hh[i] = h[i] * 2;

        for (int j = 1; j <= m; j++)
            if (t[j] == s[i])
            {
                if (j != 1)
                    qq[j] += q[j - 1];
                else
                    qq[j]++;
            }
        for (int j = 1; j <= m; j++)
            if (t[j] == s[i])
            {
                if ((m - j) != 0)
                    hh[j] += h[m - j];
                else
                    hh[j]++;
            }
    }
}

signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin >> _;

    while (_--)
    {
        solve();
    }

    return 0;
}