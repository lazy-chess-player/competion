#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

#define endl "\n"
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vl;

const int M = 55;
const int N = 55;

int graph[M][N];
int graph2[M][N];

int n, m;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void ini()
{
    memset(graph, 0, sizeof(graph));
    memset(graph2, 0, sizeof(graph2));
}
void bfs1(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx <= m + 1 && ny >= 0 && ny <= n + 1 && graph[nx][ny] == 0 && graph2[nx][ny] == 0)
        {
            graph2[nx][ny] = 1;
            bfs1(nx, ny);
        }
    }
}

void bfs2(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && graph2[nx][ny] == 0)
        {
            graph2[nx][ny] = 1;
            bfs2(nx, ny);
        }
    }
}

void solve()
{
    ini();
    cin >> m >> n;
    string t;
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = t[j - 1] - '0';
        }
    }
    bfs1(0, 0);
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph2[i][j] == 0)
            {
                cnt++;
                bfs2(i, j);
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
}