#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vl;

// 飞机结构体 包含到达时间，可盘旋时间，降落所需时间
struct Plane
{
    ll arrive, rotate, land;
};

const int N = 15;
Plane plane[N];
ll n;
bool flag = false;
bool vis[10];

void init()
{
    memset(vis, 0, sizeof(vis));
    flag = false;
}

void dfs(ll p, ll time)
{
    if (p > n)
        return;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        if (max(time, plane[i].arrive) > plane[i].arrive + plane[i].rotate)
            continue;
        vis[i] = true;
        dfs(p + 1, max(time, plane[i].arrive) + plane[i].land);
        if (p == n && max(time, plane[i].arrive) <= plane[i].arrive + plane[i].rotate)
            flag = true;
        vis[i] = false;
    }
}

void solve()
{
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> plane[i].arrive >> plane[i].rotate >> plane[i].land;
    }
    dfs(1, 0);
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
}