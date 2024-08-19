#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>
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
#include <cstdlib>
#include <iomanip>
#include <random>
#include <tuple>

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
#define sort1_all(x) sort(x.begin() + 1, x.end())

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

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

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;
typedef vector<ti3> vti3;
typedef vector<tl3> vtl3;
typedef vector<tld3> vtld3;

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
typedef priority_queue<pll> pqpll;
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

#include <cstdio>

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

typedef long double ld; // 定义长双精度类型

const ld eps = 1e-8;    // 定义浮点数的最小误差范围
const ld pi = acos(-1); // 定义圆周率π
const ld infd = 1e20;   // 定义一个较大的无穷数

// 比较函数，返回x的符号
int dcmp(ld x)
{
    if (fabs(x) < eps) // 如果x在误差范围内，认为x为0
        return 0;
    if (x < 0) // x小于0返回-1
        return -1;
    else // x大于0返回1
        return 1;
}

// 计算x的平方
ld squ(ld x) { return x * x; }

// 点结构体定义
struct Point
{
    ld x, y; // 点的x和y坐标

    // 默认构造函数，将点初始化为原点(0, 0)
    Point() { x = y = 0; }

    // 带参数构造函数，根据给定坐标初始化点
    Point(ld _x, ld _y) { x = _x, y = _y; }

    // 输入函数，从标准输入流中读取x和y坐标
    void input()
    {
        cin >> x;
        cin >> y;
    }

    // 重载==运算符，判断两个点是否相等
    friend bool operator==(Point A, Point B)
    {
        return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
    }

    // 重载<运算符，定义点的排序规则
    friend bool operator<(Point A, Point B)
    {
        return dcmp(A.x - B.x) == 0 ? dcmp(A.y - B.y) < 0 : A.x < B.x;
    }

    // 重载-运算符，计算两个点之间的向量
    friend Point operator-(Point A, Point B)
    {
        return Point(A.x - B.x, A.y - B.y);
    }

    // 重载+运算符，计算两个点的向量和
    friend Point operator+(Point A, Point B)
    {
        return Point(A.x + B.x, A.y + B.y);
    }

    // 重载*运算符，将点乘以标量
    friend Point operator*(Point A, ld k)
    {
        return Point(A.x * k, A.y * k);
    }

    // 重载/运算符，将点除以标量
    friend Point operator/(Point A, ld k)
    {
        return Point(A.x / k, A.y / k);
    }

    // 重载^运算符，计算两个向量的叉积
    friend ld operator^(Point A, Point B)
    {
        return A.x * B.y - A.y * B.x;
    }

    // 重载*运算符，计算两个向量的点积
    friend ld operator*(Point A, Point B)
    {
        return A.x * B.x + A.y * B.y;
    }

    // 计算向量的模长的平方
    ld len2() { return x * x + y * y; }

    // 计算向量的模长
    ld len() { return sqrt(len2()); }

    // 计算向量的极角
    ld angle() { return atan2(y, x); }

    // 计算以当前点为顶点的两个向量之间的夹角（单位：弧度）
    ld rad(Point A, Point B)
    {
        Point P = *this;
        return fabs(atan2((A - P) ^ (B - P), (A - P) * (B - P)));
    }

    // 将向量缩放到模长为r
    Point trunc(ld r)
    {
        ld l = len();
        if (!dcmp(l)) // 如果向量模长为0，返回原向量
            return *this;
        r /= l; // 缩放比例
        return Point(x * r, y * r);
    }

    // 将向量逆时针旋转90度
    Point rotate_left() { return Point(-y, x); }

    // 将向量顺时针旋转90度
    Point rotate_right() { return Point(y, -x); }

    // 将向量绕点P逆时针旋转ang角度
    Point rotate(Point P, ld ang)
    {
        Point v = (*this) - P;
        ld c = cos(ang), s = sin(ang);
        return Point(P.x + v.x * c - v.y * s, P.y + v.x * s + v.y * c);
    }

    // 将向量绕原点逆时针旋转ang角度
    Point rotate(ld ang) { return rotate(Point(0, 0), ang); }
};

ld area(Point A, Point B, Point C)
{
    return fabs((A - B) ^ (C - B)) / 2;
}

struct Line
{
    Point s, e; // 线段的两个端点
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
    }

    // 输入线段的两个端点坐标
    void input()
    {
        s.input();
        e.input();
    }

    // 如果终点比起点小，交换起点和终点
    void adjust()
    {
        if (e < s)
            swap(e, s);
    }

    // 判断两条线段是否相等，只有起点和终点都相同时返回 true
    friend bool operator==(Line A, Line B) { return A.s == B.s && A.e == B.e; }

    // 构造一条通过点 p 且与 x 轴成角 ang 的直线
    Line(Point p, ld ang)
    {
        s = p;
        e = p + (dcmp(ang - pi / 2) == 0 ? Point(0, 1) : Point(1, tan(ang)));
    }

    // 根据一般式直线方程 ax+by+c=0 构造直线
    Line(ld a, ld b, ld c)
    {
        if (dcmp(a) == 0)
            s = Point(0, -c / b), e = Point(1, -c / b); // 垂直于 x 轴
        else if (dcmp(b) == 0)
            s = Point(-c / a, 0), e = Point(-c / a, 1); // 垂直于 y 轴
        else
            s = Point(0, -c / b), e = Point(1, (-c - a) / b); // 普通斜率
    }

    // 计算线段的长度
    ld len() { return (e - s).len(); }

    // 计算线段的斜角（弧度制）
    ld angle2() { return atan2(e.y - s.y, e.x - s.x); }

    // 计算线段与 x 轴之间的夹角，并确保角度在 [0, pi) 之间
    ld angle()
    {
        ld k = angle2();
        if (dcmp(k) < 0)
            k += pi;
        if (dcmp(k - pi) == 0)
            k -= pi;
        return k;
    }

    // 判断点 p 与线段的位置关系
    // 返回值为1表示 p 在直线左侧；3表示 p 在直线上
    int relation(Point p)
    {
        int c = dcmp((p - s) ^ (e - s));
        return !c ? 3 : 1 + (c > 0);
    }

    // 判断点 p 是否在线段上
    bool PointOnSegment(Point p) { return dcmp((p - s) ^ (e - s)) == 0 && dcmp((p - s) * (p - e)) <= 0; }

    // 判断两条线段是否平行
    bool parallel(Line v) { return dcmp((e - s) ^ (v.e - v.s)) == 0; }

    // 判断两线段的相交情况
    // 返回值 2 表示规范相交，1 表示非规范相交，0 表示不相交
    int segcrossseg(Line v)
    {
        int d1 = dcmp((e - s) ^ (v.s - s));
        int d2 = dcmp((e - s) ^ (v.e - s));
        int d3 = dcmp((v.e - v.s) ^ (s - v.s));
        int d4 = dcmp((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && dcmp((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && dcmp((v.e - s) * (v.e - e)) <= 0) ||
               (d3 == 0 && dcmp((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && dcmp((e - v.s) * (e - v.e)) <= 0);
    }

    // 判断线段与直线的相交情况
    // 返回值 2 表示规范相交，1 表示非规范相交，0 表示不相交
    int linecrossseg(Line v)
    {
        int d1 = dcmp((e - s) ^ (v.s - s));
        int d2 = dcmp((e - s) ^ (v.e - s));
        if ((d1 ^ d2) == -2)
            return 2;
        return (d1 == 0 || d2 == 0);
    }

    // 判断两直线的相交情况
    // 返回值 0 表示平行，1 表示重合，2 表示相交
    int linecrossline(Line v)
    {
        if ((*this).parallel(v))
            return v.relation(s) == 3;
        return 2;
    }

    // 计算两条直线的交点
    Point Intersection(Line v)
    {
        ld a1 = (v.e - v.s) ^ (s - v.s);
        ld a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }

    // 计算点到直线的距离
    ld dispointtoline(Point p) { return fabs((p - s) ^ (e - s)) / len(); }

    // 计算点到线段的距离
    ld dispointtoseg(Point p)
    {
        if (dcmp((p - s) * (e - s)) < 0 || dcmp((p - e) * (s - e)) < 0)
            return min((p - s).len(), (p - e).len());
        return dispointtoline(p);
    }

    // 计算线段到线段的距离
    // 前提是两线段不相交，如果相交距离就是0
    ld dissegtoseg(Line v)
    {
        return min(min(dispointtoseg(v.s), dispointtoseg(v.e)), min(v.dispointtoseg(s), v.dispointtoseg(e)));
    }

    // 计算点 p 在直线上的投影
    Point lineprog(Point p)
    {
        return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
    }

    // 计算点 p 关于直线的对称点
    Point symmetrypoint(Point p)
    {
        Point q = lineprog(p);
        return Point(2 * q.x - p.x, 2 * q.y - p.y);
    }
};

// 凸包结构体定义
struct Polygon
{
    int n;           // 凸包的顶点数
    vector<Point> p; // 存储凸包顶点的向量
    vector<Line> l;  // 存储凸包边的向量

    // 默认构造函数，初始化凸包的顶点数为0，并清空顶点和边的向量
    Polygon()
    {
        n = 0;
        p.clear();
        l.clear();
    }

    // 带参数的构造函数，接受一个点的向量并构建凸包
    Polygon(vector<Point> a)
    {
        n = a.size(); // 设置顶点数量
        p = a;        // 设置顶点列表
        l.resize(n);  // 根据顶点数量调整边的数量
        for (int i = 0; i < n; i++)
            l[i] = Line(p[i], p[(i + 1) % n]); // 依次连接相邻的顶点，构建边
    }

    // 计算凸包的面积
    ld area()
    {
        ld ans = 0;
        // 使用凸包的顶点通过向量叉积计算面积
        for (int i = 2; i < n; i++)
            ans += (p[i] - p[0]) ^ (p[i - 1] - p[0]);
        return fabs(ans) / 2; // 返回绝对值的一半，即为凸包的面积
    }

    // 计算凸包的直径（即两点之间的最大距离）
    ld diameter()
    {
        if (n == 2)
        {
            return (p[0] - p[1]).len(); // 如果凸包只有两个顶点，则返回这两个点之间的距离
        }
        int j = 2;  // 初始化变量 j，用于追踪与当前边相对的最远顶点
        ld ans = 0; // 初始化答案变量，用于存储最大距离
        for (int i = 0; i < n; i++)
        {
            // 使用旋转卡壳算法找到最大直径
            while (((p[(i + 1) % n] - p[i]) ^ (p[j] - p[i])) < ((p[(i + 1) % n] - p[i]) ^ (p[(j + 1) % n] - p[i])))
                j = (j + 1) % n; // 更新 j，寻找使得叉积最大的点
            // 更新答案为当前计算的最大距离
            ans = max(ans, max((p[i] - p[j]).len(), (p[(i + 1) % n] - p[(j + 1) % n]).len()));
        }
        return ans; // 返回计算出的凸包直径
    }

    // 计算凸包的周长
    ld perimeter()
    {
        ld res = 0.0;
        // 如果凸包只有两个顶点，则返回这两个点之间的距离
        if (n == 2)
            return (p[0] - p[1]).len();
        // 累加每条边的长度
        for (int i = 0; i < n; i++)
        {
            res += l[i].len();
        }
        return res;
    }

    // 从输入读取凸包的顶点
    void input()
    {
        cin >> n;    // 输入顶点数
        p.resize(n); // 调整点的向量大小
        for (int i = 0; i < n; i++)
            p[i].input(); // 输入每个顶点的坐标
    }

    // 判断点是否在凸包内
    bool isPointInside(Point q)
    {
        // 遍历凸包的每一条边
        for (int i = 0; i < n; i++)
        {
            // 使用叉积法判断点 q 是否在当前边的左侧或线上
            if (((p[(i + 1) % n] - p[i]) ^ (q - p[i])) < 0)
            {
                // 如果点 q 在任意一条边的右侧，则点在凸包外
                return false;
            }
        }
        // 如果点 q 在所有边的左侧或线上，则点在凸包内或边上
        return true;
    }

    // 计算点到凸包的最短距离
    ld distanceToPoint(Point p)
    {
        ld minDist = infd; // 初始化为无穷大
        for (int i = 0; i < n; i++)
        {
            minDist = min(minDist, l[i].dispointtoseg(p));
        }
        return minDist;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    Polygon poly(p);
    while (q--)
    {
        Point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        ld r = (Point(a - b).len()) / 2.0;
        Point c = (a + b) / 2.0;
        ld mn = infd;
        if (poly.isPointInside(c))
            mn = 0.0;
        else
            mn = poly.distanceToPoint(c);
        cout << fixed << setprecision(10) << mn * mn + r * r / 2.0 << endl;
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