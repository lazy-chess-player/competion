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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

ll quickPow(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

ll cal(ll n)
{
	ll res = 1;
	while (n)
	{
		res = res * n % MOD;
		n--;
	}
	return res;
}

void solve()
{
	string s;
	cin >> s;
	int n = s.length();
	ll ans = quickPow(25, n);
	char mxChar = *max_element(s.begin(), s.end());
	char mnChar = *min_element(s.begin(), s.end());
	ll len = ll(mxChar - mnChar + 1);
	ans = ans - (26 - len);
	cout << ans << endl;
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