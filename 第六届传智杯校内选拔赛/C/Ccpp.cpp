#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

void solve()
{
	int n;
	multiset<int> nums;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		nums.insert(x);
	}
	if (n == 1 && *nums.begin() == 1)
	{
		cout << "1" << '\n';
		return;
	}
	int ans = 0;
	for (int k = 1; k <= n; k++)
	{
		multiset<int> temp = nums;
		bool falg = false;
		for (int i = 1; i <= k; i++)
		{
			int j = -1;
			for (auto x : temp)
			{
				if (x <= k - i + 1)
					j = x;
				else 
					break;
			}
			if (j == -1)
			{
				falg = true;
				break;
			}

			auto pos = temp.lower_bound(j);
			temp.erase(pos);

			int num = *temp.begin();
			temp.erase(temp.begin());
			temp.insert(num + k - i + 1);
		}
		if (falg)
			break;
		ans = k; 
	}
	cout << ans << '\n';
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