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
namespace SegCntTree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
    const int N = 2e5 + 5;
    int n;
    map<int, int> idx;
    int val[N << 1];
    int cnt[N];
    struct node
    {
        int num;
        ll sum;
    } tr[N << 2];

    void pushup(int p)
    {
        tr[p].num = tr[ls].num + tr[rs].num;
        tr[p].sum = tr[ls].sum + tr[rs].sum;
    }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            tr[p].num = cnt[l];
            tr[p].sum = cnt[l] * val[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(p);
    }

    void add(int p, int l, int r, int v, int num)
    {
        if (l == r)
        {
            tr[p].num += num;
            tr[p].sum += v * num;
            return;
        }
        int mid = (l + r) >> 1;
        if (v <= mid)
            add(ls, l, mid, v, num);
        else
            add(rs, mid + 1, r, v, num);
        pushup(p);
    }

    void add(int v, int num)
    {
        add(1, 1, n, v, num);
    }

    ll queryKth(int p, int l, int r, int k)
    {
        if (l == r)
            return tr[p].sum;
        int mid = (l + r) >> 1;
        if (k <= tr[ls].num)
            return queryKth(ls, l, mid, k);
        else
            return queryKth(rs, mid + 1, r, k - tr[ls].num);
    }

    ll queryKth(int k)
    {
        return queryKth(1, 1, n, k);
    }

    int query(int p, int l, int r, ll v)
    {
        if (l == r)
            return (v <= 0 ? 0 : (v + l - 1) / l);
        int mid = (l + r) >> 1;
        if (tr[rs].sum >= v)
            return query(rs, mid + 1, r, v);
        else
            return query(ls, l, mid, v - tr[rs].sum) + tr[rs].num;
    }

    int query(ll v)
    {
        return query(1, 1, n, v);
    }
}

using namespace SegCntTree;
void solve()
{
    int q;
    cin >> n >> q;
    vi v(1);
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(a[i]);
    }
    vector<pii> Query(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> Query[i].ft >> Query[i].sd;
        v.pb(Query[i].sd);
    }
    sort(all1(v));
    unq_all1(v);
    for (int i = 0; i < v.size(); i++)
    {
        idx[v[i]] = i + 1;
        val[i + 1] = v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[idx[a[i]]]++;
    }
    build(1, 1, n);
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