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
    int n, m;
    ll c, d;
    cin >> n >> m >> c >> d;
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '.')
            {
                rows[i]++;
                cols[j]++;
                tot++;
            }
        }
    }
    sort(all(rows));
    sort(all(cols));
    vl pre_r(n + 1);
    for (int i = 0; i < n; i++)
    {
        pre_r[i + 1] = pre_r[i] + rows[i];
    }
    vl pre_c(m + 1);
    for (int i = 0; i < m; i++)
    {
        pre_c[i + 1] = pre_c[i] + cols[i];
    }
    int max_r = (n > 0) ? rows[n - 1] : 0;
    int max_c = (m > 0) ? cols[m - 1] : 0;
    ll k_max = max(max_r, max_c);
    int pos_r = 0, pos_c = 0;
    ll ans = infll;
    for (ll k = 0; k <= k_max; k++)
    {
        while (pos_r < n && rows[pos_r] <= k)
        {
            pos_r++;
        }
        ll sum_r = pre_r[pos_r] + k * (n - pos_r);
        while (pos_c < m && cols[pos_c] <= k)
        {
            pos_c++;
        }
        ll sum_c = pre_c[pos_c] + k * (m - pos_c);
        ll mx = min({sum_r, sum_c, tot});
        ll z = tot - mx;
        ll cost = c * k + d * z;
        ans = min(ans, cost);
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