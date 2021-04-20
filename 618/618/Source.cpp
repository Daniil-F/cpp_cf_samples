#include <iostream>
#include <vector>
#include <fstream>
#include <set>

#define int int64_t

using namespace std;

vector<vector<pair<int, int> > > g;

vector<int> up;
vector<int> col;

const int mmask = 32;

struct res
{
	bool cont[mmask] = {};
	bool tri;
	int get_m()
	{
		int ret = 0;
		for (int j = 0; j < 32; j++)
			if (cont[j])
				ret |= 1 << j;
		return ret;
	}
	int tmask;
};

void dfs(int v, int par, res& ans)
{
	col[v] = 1;
	for (auto p : g[v])
	{
		int u = p.first;
		if (u == 0 || u == par)
			continue;
		int w = p.second;
		if (col[u] == -1)
		{
			ans.tri = 1;
			ans.tmask = up[v] ^ up[u] ^ w;
			dfs(u, v, ans);
		}
		if (col[u] == 1)
		{
			int mask = up[v] ^ up[u] ^ w;
			for (int j = 0; j < mmask; j++)
			{
				if (ans.cont[j])
					ans.cont[j ^ mask] = 1;
			}
			ans.cont[mask] = 1;
		}
		if (col[u] == 0)
		{
			up[u] = up[v] ^ w;
			dfs(u, v, ans);
		}
	}
	col[v] = 2;
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	cout.precision(12);
	cout << fixed;
#ifdef _DEBUG
	ifstream cin("input.txt");
#endif
	int n, m;
	cin >> n >> m;
	g.resize(n);
	col.resize(n);
	up.resize(n);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		--x, --y;
		g[x].push_back({ y, z });
		g[y].push_back({ x, z });
	}
	for (auto p : g[0])
	{
		col[p.first] = -1;
		up[p.first] = p.second;
	}
	vector<res> bl;
	for (auto p : g[0])
		if (col[p.first] == -1)
		{
			bl.push_back(res());
			dfs(p.first, 0, bl.back());
		}
	vector<int> cov(0, 1);
	for (auto a : bl)
	{
		
	}
	return 0;
}