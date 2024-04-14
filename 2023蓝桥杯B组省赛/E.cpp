#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vl;

// 飞机结构体 包含到达时间，可盘旋时间，降落所需时间
struct Plane
{
    ll arrive, rotate, land;
};

const int N = 1e5 + 5;

ll a[N];
ll dp[15];
ll n;

ll cal(ll x)
{
    if (x < 10)
        return x;
    return cal(x / 10);
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int t = cal(a[i]);
        int w = a[i] % 10;
        dp[w] = max(dp[w], dp[t] + 1);
    }
    ll ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << n - ans << endl;
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
}