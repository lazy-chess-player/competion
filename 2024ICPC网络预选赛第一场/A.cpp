#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define int long long
#define ll long long

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

#define ft first
#define sd second

void solve()
{
    vector<int> a(32);
    map<int, int> pos;
    for (int i = 0; i < 32; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int t = a[0];
    sort(a.begin(), a.end(), greater<int>());
    int p = 0;
    for (int i = 0; i < 32; i++)
    {
        if (a[i] == t)
        {
            p = i + 1;
            break;
        }
    }
    int ans = 32;
    if (p <= 30)
        ans = 16;
    if (p <= 26)
        ans = 8;
    if (p <= 19)
        ans = 4;
    if (p <= 5)
        ans = 2;
    if (p == 1)
        ans = 1;
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