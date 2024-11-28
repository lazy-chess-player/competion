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

using cd = complex<ld>;

void solve()
{
    vector<cd> w(4);
    vector<cd> z(4);
    for (int i = 1; i <= 3; ++i)
    {
        int p, q, r, s;
        scanf("%d%d%d%d", &p, &q, &r, &s);
        z[i] = cd(p, q);
        w[i] = cd(r, s);
    }

    ld p0, q0;
    cin >> p0 >> q0;
    cd z0 = cd(p0, q0);

    for (int i = 1; i <= 3; ++i)
    {
        if (z[i] == z0)
        {
            printf("%.15Lf %.15Lf\n", (ld)w[i].real(), (ld)w[i].imag());
            return;
        }
    }

    cd numerator = (z0 - z[1]) * (z[3] - z[2]) * (w[3] - w[1]);
    cd denominator = (z0 - z[2]) * (z[3] - z[1]) * (w[3] - w[2]);

    cd r = numerator / denominator;

    cd one(1.0, 0.0);
    cd fz0 = (w[1] - r * w[2]) / (one - r);

    printf("%.15Lf %.15Lf\n", (ld)fz0.real(), (ld)fz0.imag());
}

int main()
{
    // ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    scanf("%d", &_);
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：