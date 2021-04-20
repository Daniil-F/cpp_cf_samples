#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int maxcol = 1e5 + 1;
int coll[maxcol];
int colr[maxcol];

struct myqcmp
{
	bool operator ()(pair<long long, int> a, pair<long long, int> b)
	{
		return a > b;
	}
};

vector<vector<pair<int, int> > > g;

long long dijkstra(int s, int f)
{
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, myqcmp> q;
	vector<long long> ans(g.size(), -1);
	q.push({ 0, s });
	while (q.size())
	{
		int v = q.top().second;
		long long w = q.top().first;
		q.pop();
		if (ans[v] != -1)
			continue;
		ans[v] = w;
		for (auto p : g[v])
			if (ans[p.second] == -1)
				q.push({ w + p.first, p.second });
	}
	return ans[f];
}

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	--a, --b;
	g.resize(n);
	vector<int> gate(n - 1), keep(n);
	for(int &i : gate)
		cin >> i;
	for (int &i : keep)
		cin >> i;
	fill(coll, coll + maxcol, -1);
	fill(colr, colr + maxcol, n);
	for (int i = a; i < n; i++)
		if (colr[keep[i]] == n)
			colr[keep[i]] = i;
	for (int i = a; i >= 0; --i)
		if (coll[keep[i]] == -1)
			coll[keep[i]] = i;
	for (int i = a + 1, l = a; i < n; i++)
	{
		if (colr[gate[i - 1]] < i)
		{
			g[l].push_back({ i - l, i });
			continue;
		}
		if (coll[gate[i - 1]] == -1)
			break;
		l = min(l, coll[gate[i - 1]]);
		g[l].push_back({ i - l, i });
	}
	for (int i = a - 1, r = a; i >= 0; --i)
	{
		if (coll[gate[i]] > i)
		{
			g[r].push_back({ r - i, i });
			continue;
		}
		if (colr[gate[i]] == n)
			break;
		r = max(r, colr[gate[i]]);
		g[r].push_back({ r - i, i });
	}
	cout << dijkstra(a, b);
	return 0;
}