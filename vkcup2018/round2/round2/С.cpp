#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &i : arr)
		cin >> i;
	vector<int> inp = arr;
	for (int i = 0; i < n; i++)
	{
		arr[i]++;
		if (i)
			arr[i] = max(arr[i], arr[i - 1]);
	}
	for (int i = n - 2; i >= 0; --i)
		arr[i] = max(arr[i], arr[i + 1] - 1);
	long long s = 0;
	for (int i = 0; i < n; i++)
		s += arr[i] - inp[i] - 1;
	cout << s;
	return 0;
}