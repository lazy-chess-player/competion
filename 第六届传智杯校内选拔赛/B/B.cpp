#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, q, opt, l1, r1, l2, r2, i, k;
ll val, temp;

struct node
{
	int _left, _right;
	mutable ll _val;
	node(int L = 0, int R = -1, long long V = 0) :_left(L), _right(R), _val(V) {}
	bool operator < (const node& x) const
	{
		return _left < x._left;
	}
}a[N], b[N];

set<node> s;

auto split(int p)//分割
{
	auto iter = s.lower_bound(node(p));
	if (iter != s.end() && iter->_left == p)
		return iter;
	iter--;
	int l = iter->_left;
	int r = iter->_right;
	ll v = iter->_val;

	s.erase(iter);
	s.insert(node(l, p - 1, v));

	return s.insert(node(p, r, v)).first;
}

ll askInterval(int l, int r)//区间和查询
{
	ll ans = 0;
	auto itR = split(r + 1);
	auto itL = split(l);

	for (auto iter = itL; iter != itR; ++iter)
	{
		ans += (ll)(iter->_right - iter->_left + 1) * iter->_val;
	}
	return ans;
}
void tpInterval(int l, int r, ll v)//推平
{
	auto itR = split(r + 1);
	auto itL = split(l);
	s.erase(itL, itR);
	s.insert(node(l, r, v));
}

void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)//构建珂朵莉树
	{
		cin >> temp;
		s.insert(node(i, i, temp));
	}
	while (q--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> i >> val;
			tpInterval(i, i, val);
			cout << askInterval(1, n) << endl;
		}
		else if (opt == 2)
		{
			cin >> val;
			tpInterval(1, n, val);
			cout << askInterval(1, n) << endl;
		}
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