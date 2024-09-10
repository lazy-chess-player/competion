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
void solve()
{
#define ca cout << "Alice" << endl
#define cb cout << "Bob" << endl
    int n, k;
    cin >> n >> k;
    if (n <= k)
    {
        ca;
        return;
    }

    if (n % 2 == 1)
    {
        ca;
    }
    else
    {
        if (k == 1)
        {
            cb;
        }
        else if (k <= 3)
        {
            if ((n / 2) % 2 == 1)
                ca;
            else
                cb;
        }
        else if (k >= 4)
        {
            int flag = 0;

            ll now = 2;
            while (now <= k)
            {
                if ((n / now) % 2 == 1)
                    flag = 1;

                now *= 2;
            }

            if (flag)
            {
                ca;
            }
            else
            {
                cb;
            }
        }
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
    {
        solve();
    }

    return 0;
}