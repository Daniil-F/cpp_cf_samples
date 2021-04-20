#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s, s1;
	cin >> s >> s1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'C')
			s[i] = 'B';
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == 'C')
			s1[i] = 'B';
	}
	int q;
	cin >> q;
	int n, m;
	n = s.size();
	m = s1.size();
	int sum[n];
	int sum1[m];
	int dp[n];
	int dp1[m];
	dp[0] = (s[0] == 'A' ? 1 : 0);
	dp1[0] = (s1[0] == 'A' ? 1 : 0);
	for (int i = 1; i < n; i++)
	{
		if (s[i] == 'A')
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 0;
	}
	for (int i = 1; i < m; i++)
	{
		if (s1[i] == 'A')
		{
			dp1[i] = dp1[i - 1] + 1;
		}
		else
			dp1[i] = 0;
	}
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'B')
			x++;
		sum[i] = x;
	}
	x = 0;
	for (int i = 0; i < m; i++)
	{
		if (s1[i] == 'B')
			x++;
		sum1[i] = x;
	}
	for (int i = 0; i < q; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		c--;
		d--;
		int x, y;
		x = sum[b] - (a >= 1 ? sum[a - 1] : 0);
		y = sum1[d] - (c >= 1 ? sum1[c - 1] : 0);
		int k, l;
		k = min(dp[b], b - a + 1);
		l = min(dp1[d], d - c + 1);
		if (l > k)
		{
			cout << 0;
		}
		else if (l == k)
		{
			if (x > y)
				cout << 0;
			else if (abs(x - y) % 2 == 0)
			{
				cout << 1;
			}
			else
				cout << 0;
		}
		else if (l < k)
		{
			x += 2;
			if (x > y)
				cout << 0;
			else if (abs(x - y) % 2 == 0)
				cout << 1;
			else
				cout << 0;
		}
	}
	cout << endl;
	return 0;
}