#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, U;
	cin >> n >> U;
	double coef = -1;
	vector<int> arr(n);
	for (int &i : arr)
		cin >> i;
	for (int i = 0, j = 0; i < n; i++)
	{
		for (; j < n && arr[j] - arr[i] <= U; j++);
		--j;
		if (j <= i + 1)
			continue;
		coef = max(coef, double(arr[j] - arr[i + 1]) / (arr[j] - arr[i]));
	}
	cout.precision(15);
	cout << fixed;
	if (coef < 0)
		cout << -1;
	else
		cout << coef;
	return 0;
}