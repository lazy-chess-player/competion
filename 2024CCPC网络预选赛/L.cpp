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

string all[510];
void solve()
{

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
        all[i] = ')' + all[i];
    }
    int ans = 0;
    for (int i = 1; i + 1 <= n; i++)
    {
        for (int j = 1; j + 1 <= m; j++)
        {
            if (all[i][j] == 'c' && all[i][j + 1] == 'c' && all[i + 1][j] == 'p' && all[i + 1][j + 1] == 'c')
                ans++;
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
    // cin >> _;

    while (_--)
    {
        solve();
    }

    return 0;
}