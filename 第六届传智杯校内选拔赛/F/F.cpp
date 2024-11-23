#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int n;

void solve()
{
	cin >>n;
	vector<int> flowers(n + 1);
	vector<int> sums(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> flowers[i];
		sums[i] = sums[i - 1] + flowers[i];
	}
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