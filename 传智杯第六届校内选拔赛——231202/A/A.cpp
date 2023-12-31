#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;


int x, y;

int ax[] = { 3,5,6,7,8,9,9,10,12,12,14,15,15,16,18,10,21,24,24,27,28,30,33,36 };
int ay[] = { 4,12,8,24,15,12,40,24,16,35,48,20,36,30,24,21,48,28,32,45,36,45,40,44,48 };


void solve()
{
	cin >> x >> y;
	if (x > y)
		swap(x, y);
	if (x == 0 && y == 0)
	{
		cout << 0 << endl;
		return;
	}
	int ans = 0;
	while (x > 0 && y > 0)
	{
		int i = 0;
		while (x>ax[i])
		{
			i++;
		}
		i--;
		y -= ay[i];
		x -= ax[i];
		ans++;
		if (x > y)
			swap(x, y);
	}
	cout << ans << endl;
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