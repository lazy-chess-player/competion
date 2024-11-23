#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;

int n;

vector<vector<int>> tree(MAXN, vector<int>());
int childrens[MAXN];

int dfs(int p)
{
	if (tree[p].empty())
	{
		childrens[p] = 0;
	}
	else
	{
		for (auto x : tree[p])
		{
			childrens[p] += 1 + dfs(x);
		}
	}
	return childrens[p];
}


void solve()
{
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		tree[a].emplace_back(b);
	}
	dfs(1);

	int ans = 0;
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}