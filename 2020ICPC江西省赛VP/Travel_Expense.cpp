#include <cstring>
#include <iostream>
#include <math.h>
#define int long long
using namespace std;
#define int long long
#define endl '\n'
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define cy cout << "YES" << '\n'
#define cn cout << "NO" << '\n'
#define forn(i, begin, end, add) for (ll(i) = (begin); (i) <= (end); (i) += (add))  // begin是i的起始，end是i的终止，add是每次加的大小
#define rforn(i, begin, end, sub) for (ll(i) = (end); (i) >= (begin); (i) -= (sub)) // r是倒序遍历
#define vv vector
#define inf32 INT32_MAX / 2
#define inf64 INT64_MAX / 4
#define LD long double
#define PI acos(-1)
#define debug(a, b) cout << a << b
#define eps 1e-12
signed main()
{
    int n, m;
    cin >> n >> m;

    int ju[110][110]; // 初始化邻接矩阵
    memset(ju, 0x3f, sizeof(ju));
    for (int i = 1; i <= n; i++)
        ju[i][i] = 0;

    while (m--) // 构建邻接矩阵
    {
        int x, y;
        cin >> x >> y;
        ju[x][y] = min(ju[x][y], 1LL);
        ju[y][x] = ju[x][y]; // 解决重边问题（重边取最短边），自环也一样（大于0的忽略，小于0的更新）
    }

    for (int k = 1; k <= n; k++) // 处理邻接矩阵，使其中的每个元素ju[x][y]的值表示 节点x到节点y之间的最短距离
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ju[i][j] = min(ju[i][j], ju[i][k] + ju[k][j]); // 这个三层循环就是floyd算法！！！
                                                               // 动态规划证明正确性，哈哈还没学动态规划，来日再战 2023.12.16
    int q;
    cin >> q;
    while (q--)
    {
        int x, y, mon;
        cin >> x >> y >> mon;
        int dis = ju[x][y];

        int l = 0, r = mon + 1;

        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            int sum = 0;
            forn(i, 1, dis, 1)
            {

                double now = mid;
                forn(j, 1, i, 1)
                {
                    now *= now;
                    if (now > 1e9)
                        break;
                }

                sum += pow(mid, i);
                if (sum > 1e9)
                {
                    sum = 1e18;
                    break;
                }
            }

            if (sum <= mon)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        cout << l << endl;
    }

    return 0;
}