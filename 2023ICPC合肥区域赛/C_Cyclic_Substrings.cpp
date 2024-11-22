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

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
const int mod = 998244353;

struct PAM
{
    static constexpr int ALPHABET_SIZE = 26;

    struct Node
    {
        int len;
        int link;
        int cnt;
        std::array<int, ALPHABET_SIZE> next;

        Node() : len{}, link{}, cnt{}, next{} {}
    };

    std::vector<Node> t;
    int suff;
    std::string s;

    PAM()
    {
        init();
    }

    void init()
    {
        t.assign(2, Node());
        t[1].len = -1;
        t[1].link = 0;
        t[0].link = 1;
        suff = 0;
        s = " ";
    }

    int newNode()
    {
        t.emplace_back();
        return t.size() - 1;
    }

    int getlink(int x, int n)
    {
        while (s[n - len(x) - 1] != s[n])
            x = link(x);
        return x;
    }

    void add(char c, char offset = 'a')
    {
        int pos = s.size();
        s += c;
        int let = c - offset;
        int cur = getlink(suff, pos);

        if (!next(cur, let))
        {
            int p = newNode();
            t[p].link = next(getlink(link(cur), pos), let);
            t[p].len = t[cur].len + 2;
            t[cur].next[let] = p;
        }
        suff = next(cur, let);
        t[suff].cnt++;
    }

    int size() { return t.size(); }

    int len(int p) { return t[p].len; }

    int link(int p) { return t[p].link; }

    int cnt(int p) { return t[p].cnt; }

    int next(int p, int c) { return t[p].next[c]; };
};

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    PAM pam1, pam2;
    for (auto c : s)
    {
        pam1.add(c);
    }
    s += s;
    for (auto c : s)
    {
        pam2.add(c);
    }
    int tot1 = pam1.size();
    int tot2 = pam2.size();
    for (int i = tot1 - 1; i >= 0; i--)
    {
        int last = pam1.link(i);
        pam1.t[last].cnt += pam1.t[i].cnt;
        pam1.t[last].cnt %= mod;
    }
    for (int i = tot2 - 1; i >= 0; i--)
    {
        int last = pam2.link(i);
        pam2.t[last].cnt += pam2.t[i].cnt;
        pam2.t[last].cnt %= mod;
    }
    ll ans = 0;
    for (int i = 2; i < tot2; i++)
    {
        if (pam2.len(i) > n)
            continue;
        ll c = pam2.t[i].cnt;
        if (i < tot1)
            c -= pam1.t[i].cnt;
        c = (c % mod + mod) % mod;
        ans = (ans + c * c % mod * pam2.t[i].len) % mod;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：
