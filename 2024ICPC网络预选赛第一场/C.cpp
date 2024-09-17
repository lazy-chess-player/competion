#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

using namespace std;

#define endl '\n'
#define pii pair<int, int>
#define int long long
#define ll long long
#define vv vector

int n;

void solve()
{
    cin >> n;
    vv<pair<int, int>> edge(n + 10);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        edge.push_back({x, y});
    }
    sort(edge.begin(), edge.end());
    bool ok = true;
    for (int i = 1; i <= n; i++)
        if (i < edge[i - 1].first || i > edge[i - 1].second)
        {
            ok = false;
            cout << i << endl;
        }

    if (ok == false)
        cout << 0 << endl;
    else
    {
        int t = 1;
        for (int i = 0; i < n; i++)
            t = t * (edge[i].second - edge[i].first + 1) % 2;
        cout << t << endl;
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