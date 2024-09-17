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
    vector<int> ans(32, 32);
    vector<pii> r16(8);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 4 * i; j < 4 * i + 4; j++)
        {
            if (a[j] > r16[i].ft)
            {
                swap(r16[i].ft, r16[i].sd);
                r16[i].ft = a[j];
            }
            else if (a[j] > r16[i].sd)
            {
                r16[i].sd = a[j];
            }
        }
        ans[pos[r16[i].ft]] = 16;
        ans[pos[r16[i].sd]] = 16;
    }
    vector<int> r8(8);
    for (int i = 0; i < 8; i += 2)
    {
        int t1 = i;
        int t2 = i + 1;
        if (r16[t1].ft > r16[t2].sd)
        {
            r8[t1] = r16[t1].ft;
            ans[pos[r16[t1].ft]] = 8;
        }
        else
        {
            r8[t1] = r16[t2].sd;
            ans[pos[r16[t2].sd]] = 8;
        }
        if (r16[t1].sd > r16[t2].ft)
        {
            r8[t2] = r16[t1].sd;
            ans[pos[r16[t1].sd]] = 8;
        }
        else
        {
            r8[t1] = r16[t2].ft;
            ans[pos[r16[t2].ft]] = 8;
        }
    }
    vector<int> r4(4);
    for (int i = 0; i < 4; i++)
    {
        int t1 = 2 * i;
        int t2 = t1 + 1;
        if (r8[t1] > r8[t2])
        {
            ans[pos[r8[t1]]] = 4;
            r4[i] = r8[t1];
        }
        else
        {
            ans[pos[r8[t2]]] = 4;
            r4[i] = r8[t2];
        }
    }
    vector<int> r2(2);
    for (int i = 0; i < 2; i++)
    {
        int t1 = 2 * i;
        int t2 = t1 + 1;
        if (r4[t1] > r4[t2])
        {
            ans[pos[r8[t1]]] = 2;
            r2[i] = r4[t1];
        }
        else
        {
            ans[pos[r8[t2]]] = 2;
            r2[i] = r4[t2];
        }
    }
    if (r2[0] > r2[1])
    {
        ans[pos[r2[0]]] = 1;
    }
    else
    {
        ans[pos[r2[1]]] = 1;
    }
    cout << ans[0] << endl;
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