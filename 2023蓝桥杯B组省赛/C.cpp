#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define endl "\n"
#define INF 0x3f3f3f3f

void solve()
{
    ll n;
    cin >> n;
    ll a, b;
    ll mx = INF;
    ll mn = -INF;
    ll t;
    while (n--)
    {
        cin >> a >> b;
        mx = min(mx, a / b);
        mn = max(mn, (a / (b + 1)) + 1);
    }
    cout << mn << " " << mx;
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