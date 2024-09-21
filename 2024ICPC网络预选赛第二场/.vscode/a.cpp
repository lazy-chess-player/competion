#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vv vector
#define ll long long
#define pii pair<ll, ll>

void solve()
{
    int n, k;
    cin >> n >> k;
    vv<int> c(n + 1);
    int mn = 1e10;
    for (int i = 1; i <= k; i++)
        cin >> c[i], mn = min(mn, c[i]);
    map<string, vv<int>> mp;

    vv<pair<int, string>> all(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        string s;
        cin >> s;
        all[i] = {w, s};
        mp[s].push_back(w);
    }

    for (auto &a : mp)
    {
        a.second.push_back(1e10);
        sort(a.second.begin(), a.second.end());
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (auto &a : mp)
        {
            auto it = upper_bound(a.second.begin(), a.second.end(), all[i]);
            int p = (--it) - a.second.begin();
            p = max(0ll, p);
            p = min(p, mn);
            ans += p;
        }
        cout << ans << endl;
    }
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}