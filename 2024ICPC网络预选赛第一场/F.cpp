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
void solve()
{
    int n;
    cin >> n;

    vv<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    stack<pii> st;

    st.push({0, 1e10});
    map<pii, int> mp;
    for (int i = 1; i <= n; i++)
    {
        while (st.size() && st.top().second < nums[i])
            st.pop();
        mp[{st.top().first, i}] = (i - st.top().first - 1);
        st.push({i, nums[i]});
    }

    while (st.size())
        st.pop();
    st.push({n + 1, 1e10});
    for (int i = n; i >= 1; i--)
    {
        while (st.size() && st.top().second < nums[i])
            st.pop();

        mp[{i, st.top().first}] = {st.top().first - i - 1};
        st.push({i, nums[i]});
    }
    int ans = 0;
    for (auto a : mp)
    {
        ans += a.second;
    }

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