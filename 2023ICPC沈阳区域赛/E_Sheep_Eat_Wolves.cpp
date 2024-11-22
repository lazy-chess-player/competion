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
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    vector<vvi> d(2, vvi(x + 1, vi(y + 1, inf)));
    d[0][x][y] = 0;
    queue<array<int, 3>> qu;
    qu.push({0, x, y});
    while (!qu.empty())
    {
        auto [farmer, lx, ly] = qu.front();
        qu.pop();
        int rx = x - lx, ry = y - ly;
        for (int i = 0; i <= p; ++i)
        {
            for (int j = 0; j <= min(i, (farmer ? rx : lx)) && i - j <= (farmer ? ry : ly); ++j)
            {
                int sheep0 = lx + (farmer ? j : -j), wolf0 = ly + (farmer ? i - j : j - i);
                int sheep1 = rx + (farmer ? -j : j), wolf1 = ry + (farmer ? j - i : i - j);
                if (farmer && (sheep1 == 0 || sheep1 + q >= wolf1) && d[farmer ^ 1][sheep0][wolf0] > d[farmer][lx][ly] + 1)
                {
                    d[farmer ^ 1][sheep0][wolf0] = d[farmer][lx][ly] + 1;
                    qu.push({farmer ^ 1, sheep0, wolf0});
                }
                else if (!farmer && (sheep0 == 0 || sheep0 + q >= wolf0) && d[farmer ^ 1][sheep0][wolf0] > d[farmer][lx][ly] + 1)
                {
                    d[farmer ^ 1][sheep0][wolf0] = d[farmer][lx][ly] + 1;
                    qu.push({farmer ^ 1, sheep0, wolf0});
                }
            }
        }
    }
    int ans = inf;
    for (int i = 0; i <= y; ++i)
    {
        ans = min(ans, d[1][0][i]);
    }
    if (ans == inf)
        ans = -1;
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