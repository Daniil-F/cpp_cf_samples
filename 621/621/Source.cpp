#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

//#define int int64_t

using namespace std;

const int mod = 1e9 + 7;

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie();
#ifdef _DEBUG
	ifstream cin("input.txt");
#endif // _DEBUG
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int &i : arr)
		cin >> i;
	vector<vector<pair<int, int> > > cows(n + 1);
	for (int i = 0; i < m; i++)
	{
		int f, h;
		cin >> f >> h;
		int cnt = 0;
		int l = n, r = -1;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == f)
				if (++cnt == h)
					l = j;
		}
		cnt = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			if (arr[j] == f)
				if (++cnt == h)
					r = j;
		}
		if (l < n)
			cows[f].push_back({ l, r });
	}
	cows[0].push_back({ -1, -1 });
	int ans = 0;
	long long ac = 1;
	for (int i = 0; i <= n; i++)
	{
		for (auto p : cows[i])
		{
			int cnt = (i != 0);
			long long mcnt = 1;
			int x = p.first;
			for (int j = 1; j <= n; j++)
			{
				int l = 0, r = 0, b = 0;
				for (auto p : cows[j])
				{
					if (p.first < x)
						l++;
					if (p.second > x)
						r++;
					if (p.first < x && p.second > x)
						b++;
				}
				if (i == j && p.second > p.first)
					r--;
				if (j != i)
				{
					if (l == 1 && r == 1 && b == 1)
					{
						mcnt *= 2;
						mcnt %= mod;
						cnt++;
						continue;
					}
					if (r && l)
					{
						mcnt *= r * l - b;
						mcnt %= mod;
						cnt += 2;
						continue;
					}
					if (l)
					{
						mcnt *= l;
						mcnt %= mod;
						cnt++;
						continue;
					}
					if (r)
					{
						mcnt *= r;
						mcnt %= mod;
						cnt++;
						continue;
					}
				}
				else
					if (r)
					{
						cnt++;
						mcnt *= r;
						mcnt %= mod;
					}
			}
			//cerr << i << " " << p.first << " " << p.second << " " << cnt << " " << mcnt << "\n";
			if (cnt)
			{
				if (ans < cnt)
				{
					ans = cnt;
					ac = 0;
				}
				if (ans == cnt)
				{
					ac += mcnt;
				}
			}
		}
	}
	cout << ans << " " << ac % mod;
	return 0;
}