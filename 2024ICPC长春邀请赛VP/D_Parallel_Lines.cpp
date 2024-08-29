#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <cmath>
#include <random>
#include <time.h>
#include <map>

using namespace std;

#define ft first
#define sd second

typedef long long ll;

typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const ld eps = 1e-8;

const ld pi = acos(-1);

const ld infd = 1e20;

int dcmp(ld x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

ld squ(ld x) { return x * x; }

struct Point
{
    ld x, y;
    Point(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}

    friend bool operator==(const Point &A, const Point &B)
    {
        return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
    }
    friend bool operator<(const Point &A, const Point &B)
    {
        return dcmp(A.x - B.x) == 0 ? dcmp(A.y - B.y) < 0 : dcmp(A.x - B.x) < 0;
    }

    friend Point operator-(const Point &A, const Point &B)
    {
        return Point(A.x - B.x, A.y - B.y);
    }
    friend Point operator+(const Point &A, const Point &B)
    {
        return Point(A.x + B.x, A.y + B.y);
    }
    friend Point operator*(const Point &A, const ld &k)
    {
        return Point(A.x * k, A.y * k);
    }
    friend Point operator/(const Point &A, const ld &k)
    {
        return Point(A.x / k, A.y / k);
    }

    friend ld operator^(const Point &A, const Point &B)
    {
        return A.x * B.y - A.y * B.x;
    }

    friend ld operator*(const Point &A, const Point &B)
    {
        return A.x * B.x + A.y * B.y;
    }

    ld len()
    {
        return sqrt(squ(x) + squ(y));
    }
    ld len2()
    {
        return x * x + y * y;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Point> P(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i].x >> P[i].y;
    }
    vector<vector<int>> ans;

    auto check = [&](ld k) -> bool
    {
        map<ld, vector<int>> mp;
        for (int i = 1; i <= n; i++)
        {
            ld b;
            if (k == infd)
                b = P[i].x;
            else
                b = P[i].y - k * P[i].x;
            mp[b].push_back(i);
        }
        if (mp.size() != m)
            return false;
        for (auto it : mp)
        {
            if (it.sd.size() < 2)
                return false;
        }
        for (auto it : mp)
        {
            ans.push_back(it.sd);
        }
        return true;
    };

    for (int t = 0; t < 10 * m; t++)
    {
        int i = rand() % n;
        int j = rand() % n;
        if (i == j)
            j = (i + 1) % n;
        i++;
        j++;
        ld k;
        if (P[i].x == P[j].x)
            k = infd;
        else
            k = (P[i] - P[j]).y / (P[i] - P[j]).x;
        if (check(k))
            break;
    }
    for (auto it : ans)
    {
        cout << it.size() << " ";
        for (auto jt : it)
            cout << jt << " ";
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    srand(time(NULL));
    while (_--)
    {
        solve();
    }
    return 0;
}