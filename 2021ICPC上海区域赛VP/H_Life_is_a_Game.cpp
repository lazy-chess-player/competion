#include <bits/stdc++.h>

using namespace std;

#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"     // 红色
#define GREEN cout << "\033[92m"   // 绿色
#define YELLOW cout << "\033[93m"  // 蓝色
#define BLUE cout << "\033[94m"    // 品红
#define MAGENTA cout << "\033[95m" // 青色
#define CYAN cout << "\033[96m"    // 青色
#define RESET cout << "\033[0m"    // 重置

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
inline T read()
{
    T x = 0;
    int y = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            y = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * y;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

/*#####################################BEGIN#####################################*/
struct DSU
{
    vector<int> f;   // 存储父节点
    vector<int> siz; // 存储每个集合的大小

    // 默认构造函数
    DSU() {}

    // 构造函数，初始化并查集
    DSU(int n)
    {
        init(n);
    }

    // 初始化并查集
    void init(int n)
    {
        f.resize(n);                 // 调整父节点数组大小
        iota(f.begin(), f.end(), 0); // 将父节点初始化为自身
        siz.assign(n, 1);            // 每个集合初始大小为 1
    }

    // 查找操作，返回 x 的根节点
    int find(int x)
    {
        // 路径压缩
        while (x != f[x])
        {
            // 将 x 的父节点直接指向其祖父节点
            x = f[x] = f[f[x]];
        }
        return x; // 返回根节点
    }

    // 判断 x 和 y 是否在同一个集合中
    bool same(int x, int y)
    {
        return find(x) == find(y); // 如果根节点相同，则在同一个集合
    }

    // 合并操作，将 x 和 y 所在的集合合并
    bool merge(int x, int y)
    {
        x = find(x); // 找到 x 的根节点
        y = find(y); // 找到 y 的根节点
        if (x == y)
        {
            return false; // 如果已经在同一集合，返回 false
        }
        // 按秩合并，将较小的集合合并到较大的集合中
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y]; // 更新集合大小
        f[y] = x;         // 将 y 的根节点指向 x
        return true;      // 返回 true 表示合并成功
    }

    // 返回 x 所在集合的大小
    int size(int x)
    {
        return siz[find(x)]; // 返回根节点对应的集合大小
    }
};

struct Edge
{
    int u, v;
    ll w;
    bool operator<(const Edge &rhs) const
    {
        return w < rhs.w;
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vl a(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<Edge> e(m);
    for (int i = 0; i < m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    vvi adj(2 * n);
    sort(all(e));
    DSU dsu(2 * n);
    vi need(2 * n);
    int cnt = n;
    for (auto [u, v, w] : e)
    {
        u = dsu.find(u);
        v = dsu.find(v);
        if (u == v)
            continue;
        need[++cnt] = w;
        dsu.f[u] = dsu.f[v] = dsu.f[cnt];
        adj[u].pb(cnt);
        adj[cnt].pb(v);
        adj[v].pb(cnt);
        adj[cnt].pb(u);
    }
    vl sum(2 * n);
    vvi f(2 * n, vi(20));
    auto dfs = [&](auto &self, int u, int fa) -> void
    {
        sum[u] = a[u];
        f[u][0] = fa;
        for (int i = 1; i < 20; i++)
        {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
            sum[u] += sum[v];
        }
    };
    dfs(dfs, cnt, cnt);
    while (q--)
    {
        int x;
        ll k;
        cin >> x >> k;
        ll now = sum[x] + k;
        while (x != cnt)
        {
            int t = x;
            for (int i = 19; i >= 0; i--)
            {
                if (need[f[x][i]] <= now)
                    x = f[x][i];
            }
            if (x == t)
                break;
            now = sum[x] + k;
        }
        cout << now << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    // std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：