#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vv vector
#define ll long long
#define pii pair<ll, ll>

bool cmp(pair<int, pii> &a, pair<int, pii> &b)
{
    if (a.first == b.first)
        return a.second.second > b.second.second;
    return a.first > b.first;
}
void solve()
{
    int n;
    cin >> n;
    vv<pair<int, pii>> nums(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i].first;         // w
        cin >> nums[i].second.first;  // v
        cin >> nums[i].second.second; // c
    }
    sort(nums.begin() + 1, nums.end(), cmp);
    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += nums[i].second.first - sum * nums[i].second.second;
        sum += nums[i].first; // W
    }

    cout << ans << endl;
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