#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define int int64_t

using namespace std;

const int big = 1e9 + 7;
const int maxn = 1e6 + 6;
const int mod = 999999191;
const int p = 567, P = 133, Q = 69;

int32_t main()
{
#ifdef _DEBUG
	ifstream cin("input.txt");
#endif
	int n;
	cin >> n;
	vector<int> z;
	vector<int> h(1, 0);
	vector<int> ppow(1, 1);
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			cnt++;
			continue;
		}
		z.push_back(i);
		ppow.push_back((ppow.back() * p) % mod);
		h.push_back((h.back() * p + P * (cnt % 2) + Q) % mod);
		cnt = 0;
	}
	int q;
	cin >> q;
	while (q--)
	{
		int a, b, len;
		cin >> a >> b >> len;
		vector<int> ls;
		vector<int> H;
		for (int c : {a, b})
		{
			int l = c - 1;
			int r = l + len;
			int lz = lower_bound(z.begin(), z.end(), l) - z.begin();
			int rz = lower_bound(z.begin(), z.end(), r) - z.begin();
			int len = rz - lz;
			ls.push_back(len);
			if (len == 0)
			{
				H.push_back(0);
				continue;
			}
			lz++;
			H.push_back((h[rz] - h[lz] * ppow[len - 1] + mod * mod) % mod);
			int L = z[lz - 1] - l;
			int R = r - z[rz - 1] - 1;
			H.back() = (H.back() + (P * (L % 2) + Q) * ppow[len - 1]) % mod;
			H.back() = (H.back() * p + P * (R % 2) + Q) % mod;
		}
		if (H[0] == H[1] && ls[0] == ls[1])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}