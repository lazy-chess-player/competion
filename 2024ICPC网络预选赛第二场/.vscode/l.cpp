#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vv vector
#define ll long long
#define pii pair<ll, ll>
#define endl '\n'

void solve()
{
    int T;
    cin >> T;
    int now = __gcd(T + 1, 2ll);
    cout << (1 + T) / now << ' ' << 2 / now << endl;
}
signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}