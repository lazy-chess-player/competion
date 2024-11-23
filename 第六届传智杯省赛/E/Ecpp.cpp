#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>

#define fi first
#define se second
#define endl '\n'

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef pair<string, int> psi;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;
typedef vector<vi> vvi;

typedef queue <int> qi;
typedef queue <ll> ql;
typedef queue <pii> qpii;
typedef queue <psi> qpsi;

typedef priority_queue<int> pqi;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;

typedef unordered_map<int, int> umapii;
typedef unordered_map<string, int> umapsi;

const int N = 5e5 + 5;
int n, q, l, r;
char opt;

struct node
{
	int _left, _right;
	mutable int _val;
	node(int L = 0, int R = -1, int V = 0) :_left(L), _right(R), _val(V) {}
	bool operator < (const node& x) const
	{
		return _left < x._left;
	}
};

set<node> s;

auto split(int p)
{
	auto iter = s.lower_bound(node(p));
	if (iter != s.end() && iter->_left == p)
		return iter;
	iter--;
	int l = iter->_left;
	int r = iter->_right;
	int v = iter->_val;
	s.erase(iter);
	s.insert(node(l, p - 1, v));
	return s.insert(node(p, r, v)).first;
}

void add(int l, int r, char opt)
{
	auto itR = split(r + 1);
	auto itL = split(l);
	int v = opt == '+' ? 1 : -1;
	for (auto iter = itL; iter != itR; iter++)
	{
		iter->_val += v;
	}
}

bool ask(int l, int r)
{
	auto itR = split(r + 1);
	auto itL = split(l);

	for (auto iter = itL; iter != itR; iter++)
	{
		if (iter->_val > 1)
			return true;
	}
	return false;
}

void solve()
{
	cin >> q;
	const int L = 1;
	const int R = 1e9 + 5;
	s.insert(node(L, R, 0));
	while (q--)
	{
		cin >>opt>> l >> r;
		add(l, r, opt);
		if (ask(L, R))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}