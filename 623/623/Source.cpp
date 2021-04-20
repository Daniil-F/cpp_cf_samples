#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

//#define int int64_t

set<int> arr;

const int maxn = 17;
int dp [maxn + 1][1 << maxn - 2][2][2];
bool used[1 << maxn - 1];

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie();
#ifdef _DEBUG
	ifstream cin("input.txt");
#endif
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < (1 << n - i); j++)
			for (int v = 0; v < 2; v++)
				for (int u = 0; u < 2; u++)
					dp[i][j][u][v] = -1;
	for (int mask = 0; mask < (1 << n); mask++)
		dp[0][mask][0][0] = 0;
	for(int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		dp[0][x][1][0] = 0;
	}
	for (int i = 1; i <= n; i++)
		for (int mask = 0; mask < (1 << n - i); mask++)
		{
			int Mask = mask << 1;
			for (int u = 0; u < 2; u++)
				for (int v = 0; v < 2; v++)
					for (int u1 = 0; u1 < 2; u1++)
						for (int v1 = 0; v1 < 2; v1++)
						{
							if (dp[i - 1][Mask][u1][v1] == -1)
							{
								//cerr << i << " " << mask << " " << u << " " << v << " <x " << u1 << " " << v1 << "\n";
								continue;
							}
							for (int u2 = 0; u2 < 2; u2++)
							{
								if (u1 + u2 < u)
									continue;
								for (int v2 = 0; v2 < 2; v2++)
								{
									if (u1 + u2 + v1 + v2 - u < v || dp[i - 1][Mask + 1][u2][v2] == -1)
									{
										//cerr << i << " " << mask << " " << u << " " << v << " <x " << u1 << " " << v1 << " " << u2 << " " << v2 << "\n";
										continue;
									}
									cerr << i << " " << mask << " " << u << " " << v << " << " << u1 << " " << v1 << " " << u2 << " " << v2 << "\n";
									int addon = (u1 || u2) + (v1 || v2) + (v1 || v2 || u1 + u2 - u);
									if (i == 1)
										addon = u1 || u2;
									dp[i][mask][u][v] = max(dp[i][mask][u][v], dp[i - 1][Mask][u1][v1] + dp[i - 1][Mask + 1][u2][v2] + addon);
								}
							}
						}
		}
	cout << dp[n][0][0][0] + (k > 0);
	return 0;
}