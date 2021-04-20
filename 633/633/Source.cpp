#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

#define int int64_t

using namespace std;

vector<vector<int> > g;
vector<int> dp1, dp2;

int ans = 1;

void get_dp(int v, int p)
{
	for (int u : g[v]) if (u != p)
		get_dp(u, v);
	vector<int> dp2s;
	vector<int> dp1s;
	for (int u : g[v]) if (u != p)
	{
		dp2s.push_back(dp2[u]);
		dp1s.push_back(max(dp1[u], dp2[u]));
	}
	sort(dp2s.rbegin(), dp2s.rend());
	sort(dp1s.rbegin(), dp1s.rend());
	if (dp2s.size() == 0)
	{
		dp1[v] = 1;
		dp2[v] = 0;
		return;
	}
	dp2[v] = max(dp1s[0] + dp1s.size() - 1, (int)dp1s.size());
	dp1[v] = dp2s[0] + 1;
	ans = max(ans, max(dp2[v], dp1[v]));
	if (dp1s.size() > 1)
	{
		ans = max(ans, 1 + dp2s[0] + dp2s[1]);
		ans = max(ans, dp1s[0] + dp1s[1]);
	}
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie();
#ifdef _DEBUG
	ifstream cin("input.txt");
#endif
	int n;
	cin >> n;
	g.resize(n);
	dp1.resize(n);
	dp2.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	get_dp(0, -1);
	cout << ans;
	return 0;
}