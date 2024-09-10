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

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> A(n + 1);
    A[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        A[i] = A[i - 1] * i % mod;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll num = 2;
    if (cnt.size() == 1)
        num = 1;
    for (auto i : cnt)
    {
        num = (num * A[i.second]) % mod;
        // cout << num << " ";
    }
    // cout << endl;
    sort(a.begin() + 1, a.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i * a[i];
        ans -= (n - i + 1) * a[i];
    }
    cout << ans << " " << num << endl;
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