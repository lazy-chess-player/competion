#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e5 + 5;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

vi e[N];
vpii query[N];
int fa[N], vis[N], ans[M];

int find(int u)
{
    if (u == fa[u])
        return u;
    return fa[u] = find(fa[u]);
}
void tarjan(int u)
{
    vis[u] = true; // 入u时标记u
    for (auto v : e[u])
    {
        if (!vis[v])
        {
            tarjan(v);
            fa[v] = u; // 回u时v指向u
        }
    }
    // 离u时枚举LCA
    for (auto q : query[u])
    {
        int v = q.first;
        int i = q.second;
        if (vis[v])
            ans[i] = find(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        query[a].push_back({b, i});
        query[b].push_back({a, i});
    };
    for (int i = 1; i <= N; i++)
    {
        fa[i] = i;
    }
}