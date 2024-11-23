#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int n, m;

void solve()
{
	cin >> n >> m;
	if (n == 1 || m == 1)
	{
		cout << "YES" << endl;
		return;
	}
	else if ((n == 2 || m == 3)||(n == 3 || m == 2))
	{
		cout << "YES" << endl;
		return;
	}
	else
		cout << "NO" << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}