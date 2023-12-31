#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int n;
int arr1[2] = { 0 };
int arr2[2] = { 0 };

void solve()
{
	cin >>n;
	string s1; cin >> s1;
	string s2; cin >> s2;
	for (auto c : s1)
	{
		arr1[c - '0']++;
	}
	for (auto c : s2)
	{
		arr2[c - '0']++;
	}
	int ans = abs(arr1[0] - arr2[0]);
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