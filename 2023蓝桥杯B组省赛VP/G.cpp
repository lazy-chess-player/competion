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

void solve()
{
    int k;
    string s;
    char c1, c2;
    cin >> k >> s >> c1 >> c2;
    int n = s.length();
    vector<int> sum(n);
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            sum[i] = sum[i - 1];
        if (s[i] == c1)
            sum[i]++;
    }
    ll ans = 0;
    for (int i = k - 1; i < n; i++)
    {
        if (s[i] == c2)
            ans += sum[i - k + 1];
    }
    cout << ans << endl;
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