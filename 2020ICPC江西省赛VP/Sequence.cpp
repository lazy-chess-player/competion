#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>
#include <cmath>
#include <bitset>
#include <stack>
#include <math.h>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

#define int long long
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define cy cout << "YES" << '\n'
#define cn cout << "NO" << '\n'
#define forn(i, begin, end, add) for (ll(i) = (begin); (i) <= (end); (i) += (add))  // begin是i的起始，end是i的终止，add是每次加的大小
#define rforn(i, begin, end, sub) for (ll(i) = (end); (i) >= (begin); (i) -= (sub)) // r是倒序遍历
#define vv vector
#define inf32 INT32_MAX / 2
#define inf64 INT64_MAX / 4
#define LD long double
#define PI acos(-1)
#define debug(a, b) cout << a << b
#define eps 1e-12

const int N = 4e5 + 100;
ll T;

// 并查集
class UnionSet
{
public:
    vv<int> fa, val, sz;
    void init(int n)
    {
        fa = sz = vv<int>(n + 1);
        val = vv<int>(n + 1);
        forn(i, 1, n, 1)
            fa[i] = i,
            sz[i] = 1;
    }
    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]); // 路径压缩
    }
    void union_set(int x, int y)
    {

        x = find(x), y = find(y);
        if (x == y)
            return; // 根相同，直接返回
        if (sz[y] < sz[x])
            swap(x, y); // 让y是大的树
        fa[x] = y;      // 让小的树并到大的树上
        sz[y] += sz[x];

    } // 让小集合的根指向大集合，以减少路径
    int find_val(int x)
    {
        if (x != fa[x])
        {
            int t = fa[x];
            fa[x] = find_val(fa[x]); // 将路径上的更新
            val[x] += val[t];        // 更新权值
            // 注：因为根节点的权值始终为0
            // 所以在层数只有2时的反复查询并不会出现重复更新权值的错误
        }
        return fa[x];
    }
    void union_set(int x, int y, int s)
    {
        if (find_val(x) == find_val(y))
            return;
        int px = find_val(x);
        int py = find_val(y);
        if (px != py)
        {
            fa[px] = py;
            val[px] = -val[x] + val[y] + s;
        }
    }
};
ll mpow(int x, int y, int mod)
{
    int s = 1;
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
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
// 强连通分量
class Tarjan_SuoDian
{
public:
    int tot = 0; // 编号
    int cnt;     // 强连通图的编号
    stack<int> st;
    vv<int> dfn;   // 节点x第一次被访问的顺序
    vv<int> low;   // 从节点x出发，所能访问到的最早时间戳
    vv<int> instk; // 是否在栈中
    vv<int> siz;   // 强连通分量的大小
    vv<int> scc;   // 某一个点在哪一个强连通分量中
    vv<vv<int>> e;
    void init(int n)
    {
        cnt = 0, tot = 0;
        dfn = low = siz = scc = vv<int>(n + 1);
        instk = vv<int>(n + 1);
    }
    void tarjan(int x, vv<vv<int>> &e)
    {
        dfn[x] = low[x] = ++tot;
        st.push(x), instk[x] = true;
        for (int y : e[x])
        {
            // if(y==x) 出现自环
            if (!dfn[y])
            {
                tarjan(y, e);
                low[x] = min(low[x], low[y]);
            }
            else if (instk[y])
            { // y还没往下走，所以用dfn更新
                low[x] = min(low[x], dfn[y]);
            }
            // 如果一个点既不在栈中，又已经走过了，不需要再走了，因为横跨边无法更新任何东西
        }
        // 离开x时，记录scc
        if (dfn[x] == low[x])
        {
            int y;
            ++cnt;
            do
            {
                y = st.top();
                st.pop();
                instk[y] = false;
                scc[y] = cnt;
                ++siz[cnt]; // 强连通分量的大小

            } while (y != x);
        }
    }
};
// eDCC缩点
struct eDCC_SuoDian
{
    // eDCC，极大的不包含割边的连通块
    struct edge
    {
        int v, ne;
    };
    vv<edge> e;
    vv<int> h;
    int idx = 1, tot = 0;
    vv<int> dfn, low;
    stack<int> st;
    vv<int> dcc;
    int cnt = 0;
    vv<int> bri, sz;
    void add(int a, int b)
    { // 第一条边编号从2开始
        e[++idx].v = b;
        e[idx].ne = h[a];
        h[a] = idx;
    }
    void init(int n, int m, vv<pii> &all)
    {
        e = vv<edge>(2 * m + 10);
        sz = bri = dcc = dfn = low = h = vv<int>(2 * m + 100);
        idx = 1;
        cnt = tot = 0;

        for (auto a : all)
        {
            add(a.first, a.second);
            add(a.second, a.first);
        }
        forn(i, 1, n, 1)
        {
            if (!dfn[i])
                tarjan(i, 1);
        }
    }
    void tarjan(int x, int in_edge)
    {
        dfn[x] = low[x] = ++tot;
        st.push(x);
        for (int i = h[x]; i; i = e[i].ne)
        {
            int y = e[i].v;
            if (!dfn[y])
            {
                tarjan(y, i);
                low[x] = min(low[x], low[y]);
                if (low[y] > dfn[x])
                    bri[i] = bri[i ^ 1] = true;
            }
            else if (i != (in_edge ^ 1))
                low[x] = min(low[x], dfn[y]);
        }
        if (dfn[x] == low[x])
        {
            ++cnt;
            while (1)
            {
                int y = st.top();
                st.pop();
                dcc[y] = cnt;
                if (y == x)
                    break;
            }
        }
    }
};
class Dijkstra
{
public:
    priority_queue<pair<int, int>> q;
    void Heap_dijkstra(int s, vv<vv<pii>> &e, vv<ll> &d)
    {
        /*变量是原点，边集，距离集*/
        priority_queue<pii> q;
        vv<int> vis(d.size());
        d[s] = 0;
        q.push({0, s});
        while (q.size())
        {
            auto t = q.top();
            q.pop();
            int u = t.second;
            if (vis[u])
                continue;

            vis[u] = 1;
            for (auto ed : e[u])
            {
                int v = ed.first, w = ed.second;
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    q.push({-d[v], v});
                }
            }
        }
    }
    void dfs_path(int u, int s)
    { // 找的是到达u的最短路径
        if (u == s)
        {
            cout << u << " ";
            return;
        }

        // dfs_path(pre[u]);
        cout << u << " ";
    }
};
// 负边权最短路
class Bellman_Ford
{
    /*
    执行n-1轮因为最短路的边数最多是n-1轮
    每轮执行m次，尝试松弛m条边
    如果第n轮还有可以松弛的边，则说明存在负环，
    因为可以一直无限走那个环来松弛各个边
    */
public:
    queue<int> q;
    bool Bellman_ford(int s, vv<vv<pii>> &e, vv<ll> &d)
    {
        d[s] = 0;
        int n = d.size() - 1;
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            flag = 0;
            for (int u = 1; u <= n; u++)
            {
                if (d[u] == inf64)
                    continue; // 说明这个点还没有到达过，而无穷的点不可能让别的点到的更小
                for (auto ed : e[u])
                {
                    int v = ed.first;
                    int w = ed.second;
                    if (d[v] > d[u] + w)
                    {
                        d[v] = d[u] + w;
                        flag = true;
                    }
                }
            }
            if (!flag)
                break;
        }

        return flag;
    }
};
// 逆元求解组合数
class Cn
{
public:
    vv<ll> fac, inv, finv;
    int mod;
    void init(int n, int mod)
    {
        fac.assign(n + 1, 1ll);
        finv = inv = fac;
        this->mod = mod;
        for (int i = 1; i < n; i++)
            fac[i] = fac[i - 1] * i % mod;
        for (int i = 2; i < n; i++)
            inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        for (int i = 2; i < n; i++)
            finv[i] = finv[i - 1] * inv[i] % mod;
    }

    // A_{a}^{b}
    ll A(int a, int b)
    {
        return fac[a] * finv[a - b] % mod;
    }

    // C_{a}^{b}
    ll C(int a, int b)
    { // a是底数
        if (a < 0 || b > a || b < 0)
            return 0;
        else
            return fac[a] * finv[a - b] % mod * finv[b] % mod;
    }
};
// 最小生成树
class Kruskal
{
public:
    bool cmp(pair<int, pii> &a, pair<int, pii> &b)
    {
        return a.first < b.first;
    }
    int ans = 0;
    vv<pii> tree;
    bool kruskal(int n, vv<pair<int, pii>> &e)
    {
        ans = 0;
        int cnt = 0;
        UnionSet ust;
        ust.init(n + 1);
        int m = e.size() - 1;
        sort(e.begin(), e.end()); // 算法瓶颈在这里，O(mlogm)

        for (int i = 1; i <= m; i++)
        { // 依次将m条边中满足条件的放入集合当中
            int x = ust.find(e[i].second.first);
            int y = ust.find(e[i].second.second);
            if (x != y)
            {
                tree.push_back({e[i].second.first, e[i].second.second});
                ust.union_set(x, y);
                ans += e[i].first;
                cnt++;
            }
        }

        return cnt == n - 1;
    }
};
// 重链刨分
struct Heavy_chain_splitting
{
    vv<int> fa;  // 存u的父节点
    vv<int> dep; // 存u的深度
    vv<int> son; // 存u的重儿子
    vv<int> sz;  // 存以u为根的子树的节点数
    vv<int> top; // 存u所在重链的顶点的
    vv<vv<int>> e;

    void init(int n, int s)
    {
        fa = vv<int>(n + 1);
        dep = vv<int>(n + 1);
        son = vv<int>(n + 1);
        sz = vv<int>(n + 1);
        top = vv<int>(n + 1);
        e = vv<vv<int>>(n + 1);
        dfs1(s, 0);
        dfs2(s, 0);
    }
    void dfs1(int u, int father)
    { // 搜fa,dep,son数组，O(n)
        fa[u] = father, dep[u] = dep[father] + 1, sz[u] = 1;
        for (int v : e[u])
        {
            if (v == father)
                continue;

            dfs1(v, u);
            sz[u] += sz[v];

            if (sz[son[u]] < sz[v])
                son[u] = v;
        }
    }
    void dfs2(int u, int t)
    { // 搜top数组，O(n)
        top[u] = t;
        if (!son[u])
            return;      // 无重儿子也就相当于无儿子
        dfs2(son[u], t); // 搜重儿子
        for (int v : e[u])
        {
            if (v == fa[u] || v == son[u])
                continue;
            dfs2(v, v); // 搜轻儿子，轻儿子的top一定是自己
        }
    }
    int lca(int u, int v)
    { // O(logn)
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v); // 让u是深的那个点
            u = fa[top[u]]; // 爬到链头的父节点
        }
        return dep[u] < dep[v] ? u : v; // 返回深度浅的点
    }
};
struct Tuopu_order
{
    queue<int> q;
    /*是无环图返回1，不是无环图返回0*/
    bool topsort(vv<vv<pii>> &e, vv<int> du)
    {

        int n = e.size() - 1;

        forn(i, 1, n, 1)
        {
            if (!du[i])
                q.push(i);
        }

        int tot = 0;

        while (q.size())
        {

            int nd = q.front();
            q.pop();
            tot++;

            for (auto a : e[nd])
            {
                du[a.first]--;
                if (!du[a.first])
                    q.push(a.first);
            }
        }

        return tot == n;
    }
};
struct Prime_sieve
{
    /*质数数组下表从1开始*/
    vv<int> primes;
    int cnt = 0;
    vv<bool> st;
    void init(int n)
    {
        primes = vv<int>(n);
        st = vv<bool>(n + 10);
        cnt = 0;
        get_primes(n);
    }
    void get_primes(int n)
    {
        for (int i = 2; i <= n; i++)
        {
            if (!st[i])
                primes[++cnt] = i;

            for (int j = 1; primes[j] <= n / i; j++)
            {
                st[primes[j] * i] = 1;
                if (i % primes[j] == 0)
                    break;
            }
        }
    }
};
// KMP
struct KMP
{

    // ne[i]表示s[1,i]的相同前后缀的最长长度
    void get_next(string s, vector<int> &ne)
    {
        int n = s.size();
        ne[0] = -1; // 初始值
        for (int i = 1, j = -1; i < n; i++)
        {

            while (j != -1 && s[i] != s[j + 1])
                j = ne[j]; // 回跳到已经匹配成功的字符的下标处

            if (s[i] == s[j + 1])
                j++;

            ne[i] = j;
        }
    }
    int kmp(string s, string ss)
    { // s 是主串

        int n = s.size(), m = ss.size();

        vector<int> next(m);
        get_next(ss, next);
        for (int i = 0, j = -1; i < n; i++)
        {

            while (-1 != j && s[i] != ss[j + 1]) // 一个是s,一个是ss
                j = next[j];

            if (s[i] == ss[j + 1]) // 一个是s,一个是ss
                j++;

            if (j == m - 1)
            { // m-1
                return i - j;
            }
        }
        return -1;
    }
};
// 二分图染色
struct Judge_two
{
    /*是二分图返回1，不是二分图返回0*/
    int flag = 1;
    void dfs_judge_two_map(int u, int c, vv<vv<int>> &e, vv<int> &color)
    {
        color[u] = c;
        for (auto v : e[u])
            if (!color[v])
                dfs_judge_two_map(v, 3 - c, e, color);
            else if (color[v] == c)
                flag = 0;
    }
};
struct Huan_tree
{
    int flag = 0;
    int r1 = 0, r2 = 0;
    void find(int u, int fa, vv<vv<int>> &e, vv<int> &vis)
    {               // 找两个根
        vis[u] = 1; // 进栈标记
        for (auto v : e[u])
        {
            if (vis[v] == 1)
            { // 找到根了
                r1 = v, r2 = u;
                flag = 1;
                return;
            }
            else if (vis[v] == 2)
            { // 这条路是其他的路的头路径
                return;
            }

            if (v == fa)
                continue;

            find(v, u, e, vis);
        }
        vis[u] = 2; // 出栈标记
    }
};
struct Hash
{

    vv<ull> p, h;
    int P = 1331;

    void init(string &s)
    {
        int n = s.size();
        s = ')' + s;
        p = h = vv<ull>(n + 1);
        p[0] = 1, h[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i];
        }
    }

    ull get(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
};
const int mod = 1e9 + 7;

vv<int> primes;
int cnt = 0;
vv<bool> st;
vv<int> g;
void init(int n)
{
    primes = vv<int>(n);
    st = vv<bool>(n + 10);
    cnt = 0;
    g = vv<int>(n + 1);
}
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[++cnt] = i;

        for (int j = 1; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = 1;
            g[primes[j] * i] -= g[primes[j]] + g[i];
            if (i % primes[j] == 0)
                break;
        }
    }
}

const int MAX_LEN = 1000;
int seg_tree[MAX_LEN << 2];
int Lazy[MAX_LEN << 2];
int arr[MAX_LEN];
// 从下往上更新 节点
void push_up(int root)
{
    seg_tree[root] = min(seg_tree[root << 1], seg_tree[root << 1 | 1]); // 最小值改min
}
// 从上向下更新，左右孩子
void push_down(int root, int L, int R)
{
    if (Lazy[root])
    {
        Lazy[root << 1] += Lazy[root];
        Lazy[root << 1 | 1] += Lazy[root];
        int mid = (L + R) >> 1;
        seg_tree[root << 1] += Lazy[root] * (mid - L + 1);
        seg_tree[root << 1 | 1] += Lazy[root] * (R - mid);
        Lazy[root] = 0;
    }
}
// 建树
//[L,R]就是对应arr数组里面的数
void build(int root, int L, int R)
{
    Lazy[root] = 0;
    if (L == R)
    {
        seg_tree[root] = arr[L];
        return;
    }
    int mid = (L + R) >> 1;
    build(root << 1, L, mid);
    build(root << 1 | 1, mid + 1, R);
    push_up(root);
}

// 区间查询
// 查找区间[LL,RR]的最大/小值
int query(int root, int L, int R, int LL, int RR)
{
    if (LL <= L && R <= RR)
        return seg_tree[root];
    push_down(root, L, R); // 每次访问都去检查Lazy 标记
    int Ans = inf64;
    int mid = (L + R) >> 1;
    if (LL <= mid)
        Ans = min(Ans, query(root << 1, L, mid, LL, RR)); // 最小值改min
    if (RR > mid)
        Ans = min(Ans, query(root << 1 | 1, mid + 1, R, LL, RR)); // 最小值改min
    return Ans;
}

// 单点修改 可以改为某值，或者+-某值
// 把pos位置的值改成val
void update(int root, int L, int R, int pos, int val)
{
    if (L == R)
    {
        seg_tree[root] = val; // 点直接变为某值
        return;
    }
    int mid = (L + R) >> 1;
    if (pos <= mid)
        update(root << 1, L, mid, pos, val);
    else
        update(root << 1 | 1, mid + 1, R, pos, val);
    push_up(root);
}

void solve()
{

    int n;
    cin >> n;

    int q;
    cin >> q;
    forn(i, 1, n, 1)
            cin >>
        arr[i];
    forn(i, 1, 4 * n, 1)
        seg_tree[i] = inf64;

    build(1, 1, n);

    while (q--)
    {

        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;

            update(1, 1, n, a, b);
            arr[a] = b;
        }
        else
        {
            int a;
            cin >> a;

            int l = 0, r = a;

            while (l + 1 != r)
            {
                int mid = l + r >> 1;
                if (query(1, 1, n, mid, a) >= arr[a])
                    r = mid;
                else
                    l = mid;
            }

            int nl = r;

            l = a, r = n + 1;

            while (l + 1 != r)
            {
                int mid = l + r >> 1;

                if (query(1, 1, n, a, mid) >= arr[a])
                    l = mid;
                else
                    r = mid;
            }
            int nr = l;

            cout << (a - nl + 1) * (nr - a + 1) << endl;
        }
    }
}
signed main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    T = 1;
    // cin >> T;
    while (T--)
        solve();
}