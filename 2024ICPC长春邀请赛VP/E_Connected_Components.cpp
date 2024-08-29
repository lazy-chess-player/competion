#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define ft first
#define sd second

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
void solve()
{
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].ft >> v[i].sd;
        v[i].ft -= i;
        v[i].sd -= i;
        v[i].sd *= -1;
    }
    sort(v.begin(), v.end());
    vector<pii> stk;
    pii infp = {inf, inf};
    for (auto [x, y] : v)
    {
        pii tmp = infp;
        while (stk.size() && stk.back().sd <= y)
        {
            if (stk.back().sd < tmp.sd)
                tmp = stk.back();
            stk.pop_back();
        }
        if (tmp != infp)
            stk.push_back(tmp);
        else
            stk.push_back({x, y});
    }
    cout << stk.size() << endl;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}