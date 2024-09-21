#include <vector>
#include <iostream>
using namespace std;

#define int long long
#define vv vector
#define ll long long
#define pii pair<ll, ll>
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    if (n % 4 == 0)
    {
        cout << "NO\n";
        return;
    }
    int t = n >> 1;
    vector<int> ans(32, -1);
    ans[31] = 1;
    for (int i = 0; i < 31; i++)
    {
        if (t & (1ll << i))
            ans[i] = 1;
    }
    if (n % 2 == 0)
        ans[0] = 0;
    auto cal = [&]() -> int
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            res += ans[i] * (1ll << i);
        }
        return res;
    };
    // cout << cal() << endl;
    cout << "YES\n";
    for (int i = 0; i < 32; i++)
    {
        cout << ans[i] << " \n"[(i + 1) % 8 == 0];
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
        solve();

    return 0;
}