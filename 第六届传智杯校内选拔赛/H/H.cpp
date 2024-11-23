#include <iostream>
#include<vector>

typedef long long ll;

using namespace std;

const int N = 2e5 + 5;

ll n, k, a[N], x, len;
ll p[2];
bool flag;

void lose(bool v)
{
	if (abs(p[0] - p[1]) <= x)
	{
		if (len % 2)
			p[1] = p[0];
		else 
			p[0] = p[1];
		return;
	}
	if (p[1] >= p[0])
		if (len % 2)
			p[1] -= x;
		else
			p[0] += x;
	else
		if (len % 2)
			p[1] += x;
		else 
			p[0] -= x;
}

void win(bool v)
{
	if (p[v ^ 1] > p[v])
	{
		swap(p[v ^ 1], p[v]);
		v ? p[1] += x : p[1] -= x;
	}
	else
		if (len % 2)
			v ? p[1] += x : p[1] -= x;
		else 
			v ? p[0] -= x : p[0] += x;
}

void solve()
{
	cin >> n >> k;
	for ( int i = 1; i <= n; i++)
	{
		cin>>a[i];
		i & 1 ? p[1] += a[i] : p[0] += a[i];
	}
	len = n + 1;
	if (k % 2) 
		flag = true;
	else 
		flag = false;
	for (int i = 1; i <= k; i++)
	{
		cin >> x;
		x = abs(x);
		if (i % 2)
			if (flag) 
				win(1);
			else 
				lose(1);
		else
			if (flag) 
				lose(0);
			else 
				win(0);
		len++;
	}
	cout << p[1] - p[0];
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