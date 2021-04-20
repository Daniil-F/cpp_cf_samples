#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;
int sd[maxn] = {};

int main()
{
	for (int i = 2; i < maxn; i++)
		if (!sd[i])
			for (int j = i + i; j < maxn; j += i)
				sd[j] = i;
	int n;
	cin >> n;
	int ans = n;
	for (int j = n; j > n - sd[n]; --j)
		if (sd[j])
		{
			//cerr << j << " " << sd[j] << "\n";
			ans = min(ans, j - sd[j] + 1);
		}
	cout << ans;
	return 0;
}