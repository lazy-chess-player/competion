#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <numeric>

#define endl '\n'

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
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffffLL

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
    RED;                              \
    cout << #x << " : " << x << endl; \
    RESET;

// 绿色
#define DEBUG2(x)                     \
    GREEN;                            \
    cout << #x << " : " << x << endl; \
    RESET;

// 蓝色
#define DEBUG3(x)                     \
    BLUE;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 品红
#define DEBUG4(x)                     \
    MAGENTA;                          \
    cout << #x << " : " << x << endl; \
    RESET;

// 青色
#define DEBUG5(x)                     \
    CYAN;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 黄色
#define DEBUG6(x)                     \
    YELLOW;                           \
    cout << #x << " : " << x << endl; \
    RESET;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t lll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pll> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpl;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<ll, ll> mll;
typedef map<ll, bool> mlb;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<char, bool> mcb;
typedef map<string, int> msi;
typedef map<string, ll> msl;
typedef map<int, bool> mib;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

template <typename T>
inline void read(T &x)
{
    T f = 1;
    x = 0;
    char ch = getchar();
    while (0 == isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (0 != isdigit(ch))
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        x = ~(x - 1);
        putchar('-');
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

/*#####################################BEGIN#####################################*/

typedef __int128_t lll;
typedef pair<lll, lll> P;

#define x first
#define y second

// 叉乘
lll cross(P a, P b)
{
    return a.x * b.y - a.y * b.x;
}

// 点积
lll mul(P a, P b)
{
    return a.x * b.x + a.y * b.y;
}

// 点平方和
lll mul(P a)
{
    return a.x * a.x + a.y * a.y;
}

// 计算矢量
P del(P a, P b)
{
    return {a.x - b.x, a.y - b.y};
}

void solve()
{
    int n;
    read(n);

    P C;
    read(C.x);
    read(C.y);

    lll R;
    read(R);

    vector<P> a(n);
    for (int i = 0; i < n; i++)
    {
        read(a[i].x);
        read(a[i].y);
    }
    lll ans = 0;
    lll S = 0;
    for (int l = 0, r = l + 1; l < n; l++)
    {
        while (1)
        {
            // 处理首尾循环
            int rr = r % n + 1;
            // 计算新加点是否在左边界与圆心连线的另一侧
            lll s = cross(del(a[rr], a[l]), del(C, a[l]));
            // 如果在另一侧，说明新加边与圆相交或凸包包含了圆，移动l
            if (s <= 0)
                break;
            // s同时也是新加边与圆心构成的三角形的面积的两倍，利用s=len*d计算边与圆心的距离
            // 如果距离小于R，说明新加边与圆相交，移动l
            if (s * s < mul(del(a[rr], a[l])) * R * R)
                break;
            // 利用叉乘公式计算凸包新增加的三角形面积
            S += cross(del(a[r], a[l]), del(a[rr], a[l]));
            // 移动r
            r = rr;
        }
        ans = max(ans, S);
        // 处理首尾循环
        int ll = l % n + 1;
        // 减去左边界的三角形面积
        S -= cross(del(a[r], a[l]), del(a[r], a[ll]));
    }
    write(ans);
    putchar('\n');
}

int main()
{
    // ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    read(_);
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：