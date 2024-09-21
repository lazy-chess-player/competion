#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vv vector
#define ll long long
#define pii pair<ll, ll>

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll sum = 1500;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum >= 4000)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
}
signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin >> t;

    while (_--)
        solve();

    return 0;
}