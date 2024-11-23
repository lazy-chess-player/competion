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

ll val[26][26];
ll sum = 0;

struct Trie
{
    static const int MAX_LENGTH = 5e6 + 5; // 最大节点数，根据需求调整
    int son[MAX_LENGTH][26];               // 存储每个节点的子节点，26个小写字母
    ll cnt[MAX_LENGTH];                    // 存储以每个节点结尾的单词数量
    int idx;                               // 当前使用的节点编号

    // 构造函数，初始化所有数据
    Trie() : idx(0)
    {
        init();
    }

    void init()
    {
        // 重新初始化所有节点
        for (int i = 0; i <= idx; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                son[i][j] = 0;
            }
            cnt[i] = 0;
        }
        idx = 0;
    }

    // 插入一个字符串到 Trie 中
    void insert(const string &s)
    {
        int p = 0; // 从根节点开始
        for (char ch : s)
        {
            int u = ch - 'a'; // 计算字符对应的下标
            if (!son[p][u])
                son[p][u] = ++idx; // 创建新节点
            for (int j = 0; j < 26; j++)
            {
                if (j == u)
                    continue;
                val[u][j] += cnt[son[p][j]];
            }
            p = son[p][u]; // 移动到子节点
            cnt[p]++;      // 更新以当前节点结尾的单词数量
        }
        for (int i = 0; i < 26; i++)
        {
            sum += cnt[son[p][i]];
        }
    }

    // 查询字符串 s 的单词数量
    int query(const string &s)
    {
        int p = 0; // 从根节点开始
        for (char ch : s)
        {
            int u = ch - 'a'; // 计算字符对应的下标
            if (!son[p][u])
                return 0;  // 字符串不存在
            p = son[p][u]; // 移动到子节点
        }
        return cnt[p]; // 返回以当前节点结尾的单词数量
    }
} trie;
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }
    while (q--)
    {
        string s;
        cin >> s;
        ll ans = sum;
        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                ans += val[s[i] - 'a'][s[j] - 'a'];
                // cout << ans << " ";
            }
            // cout << "\n";
        }
        cout << ans << "\n";
        // cout << "\n";
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