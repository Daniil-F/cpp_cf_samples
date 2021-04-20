#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

#define int int64_t

int p = 228322;

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int32_t main()
{
#ifdef _DEBUG
	ifstream cin("input.txt");
#endif // _DEBUG
	ios::sync_with_stdio(0);
	cin.tie();
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<pair<vector<int>, int> >g(n);
		for (int i = 0; i < n; i++)
			cin >> g[i].second;
		for (int i = 0; i < m; i++)
		{
			int v, u;
			cin >> v >> u;
			--v, --u;
			g[u].first.push_back(v);
		}
		for (int i = 0; i < n; i++)
			sort(g[i].first.begin(), g[i].first.end());
		int ans = 0;
		sort(g.begin(), g.end());
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			if (i && g[i].first != g[i - 1].first)
			{
				if (g[i - 1].first.size())
					ans = gcd(ans, cur);
				cur = 0;
			}
			cur += g[i].second;
		}
		cout << gcd(ans, cur) << "\n";
	}
	return 0;
}