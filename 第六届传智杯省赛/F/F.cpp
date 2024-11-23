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
#include <bitset>

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

const ll N = 1e8 + 5;
const ll MAXN = 1e8 + 5;

bitset<MAXN> pri;
ll primes[N];
ll priLen = 0;

void ehrlichSieve(ll n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!pri[i])
			primes[++priLen] = i;
		for (int j = 1; primes[j] * i <= n; j++)
		{
			pri[primes[j] * i] = 1;
			if (i % primes[j] == 0)
				break;
		}
	}
}

ll cal(ll x)
{
	ll cnt = 0;
	while(x != 1)
	{
		if (pri[x])
		{
			cnt++;
			break;
		}
		for (int i = 0; i < priLen; i++)
		{

		}

	}
	return cnt;
}

void solve()
{
	ehrlichSieve(N);
	ll n; cin >> n;
	ll x;
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