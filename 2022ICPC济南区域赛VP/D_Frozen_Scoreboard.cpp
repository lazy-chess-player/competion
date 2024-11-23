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

struct node
{
    string sta;
    int time;
    bool solved;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vector<vector<node>> Q(m);
        for (int j = 0; j < m; j++)
        {
            string t;
            cin >> ws;
            getline(cin, t);
            if (t.empty())
            {
                Q[j].pb(node{".", 0, false});
                continue;
            }
            if (t[0] == '+')
            {
                int x, y;
                sscanf(t.c_str(), "+%d/%d", &x, &y);
                Q[j].pb(node{t, 20 * (x - 1) + y, true});
            }
            else if (t[0] == '-')
            {
                int x;
                sscanf(t.c_str(), "-%d", &x);
                Q[j].pb(node{t, 0, false});
            }
            else if (t[0] == '?')
            {
                int x, y;
                sscanf(t.c_str(), "? %d %d", &x, &y);
                string noTry = "- " + to_string(y);
                Q[j].pb(node{noTry, 0, false});
                for (int t = y - x + 1; t <= y; t++)
                {
                    for (int re = 240; re <= 299; re++)
                    {
                        string sta = "+ " + to_string(t) + "/" + to_string(re);
                        int dirt = 20 * (t - 1) + re;
                        Q[j].pb(node{sta, dirt, true});
                    }
                }
            }
            else
            {
                Q[j].pb(node{".", 0, false});
            }
        }
        vector<string> sol(m, "");

        auto dfs = [&](auto &self, int idx, int curA, int curB) -> bool
        {
            if (idx == m)
            {
                return (curA == a) && (curB == b);
            }
            for (auto &opt : Q[idx])
            {
                int nowA = curA + (opt.solved ? 1 : 0);
                int nowB = curB + (opt.solved ? opt.time : 0);
                if (nowA > a || nowB > b)
                {
                    continue;
                }
                sol[idx] = opt.sta;
                if (self(self, idx + 1, nowA, nowB))
                    return true;
            }
            return false;
        };

        if (dfs(dfs, 0, 0, 0))
        {
            Yes;
            for (int j = 0; j < m; j++)
            {
                cout << sol[j] << "\n";
            }
        }
        else
        {
            No;
        }
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