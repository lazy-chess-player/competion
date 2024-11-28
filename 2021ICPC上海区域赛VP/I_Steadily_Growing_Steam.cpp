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
void solve()
{
    int n, k;
    cin >> n >> k;
    vi v(n + 1);
    vi t(n + 1);
    int offset = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> t[i];
        offset += t[i];
    }
    vvl f(2 * offset + 1, vl(k + 1, -infll));
    vvl g(2 * offset + 1, vl(k + 1, -infll));
    f[offset][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l <= 2 * offset; l++)
            {
                g[l][j] = max(g[l][j], f[l][j]);
                if (l >= t[i])
                    g[l][j] = max(g[l][j], f[l - t[i]][j] + v[i]);
                if (l + t[i] <= 2 * offset)
                    g[l][j] = max(g[l][j], f[l + t[i]][j] + v[i]);
                if (l >= 2 * t[i] && j >= 1)
                    g[l][j] = max(g[l][j], f[l - 2 * t[i]][j - 1] + v[i]);
                if (l + 2 * t[i] <= 2 * offset && j >= 1)
                    g[l][j] = max(g[l][j], f[l + 2 * t[i]][j - 1] + v[i]);
            }
        }
        swap(f, g);
    }
    ll ans = -infll;
    for (int j = 0; j <= k; j++)
    {
        ans = max(ans, f[offset][j]);
    }

    cout << ans << "\n";
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