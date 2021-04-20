#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxh = 10001;

bool cbr[maxh] = {};
int ntr[maxh] = {};
int dp[maxh] = {};

int main()
{
	cbr[0] = 1;
	vector<int> useful;
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	vector<int> b(n);
	for (int &i : a)
		cin >> i;
	for (int &i : b)
		cin >> i;
	for (int i = 0; i < n; i++)
	{
		if (b[i])
		{
			useful.push_back(a[i]);
			continue;
		}
		for (int j = maxh - 1; j >= 0; --j)
			if (cbr[j] && j + a[i] < maxh)
				cbr[j + a[i]] = 1;
	}
	sort(useful.begin(), useful.end());
	reverse(useful.begin(), useful.end());
	for (int i : useful)
	{
		for (int j = maxh - 1; j >= 0; --j)
			if (cbr[j] && j + i < maxh)
			{
				int nv = dp[j] + (j >= l && j <= r);
				if (nv > dp[j] || !cbr[i + j])
				{
					dp[i + j] = nv;
					cbr[i + j] = 1;
					ntr[i + j] = ntr[j] + 1;
				}
				else if (nv == dp[j])
					ntr[i + j] = min(ntr[i + j], ntr[j] + 1);
			}
	}
	int ans = 0;
	for (int i = 0; i < maxh; i++)
		ans = max(ans, dp[i] + (cbr[i] && i >= l && i <= r && ntr[i] < useful.size()));
	cout << ans;
	return 0;
}