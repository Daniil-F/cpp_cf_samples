#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int maxv = 1.5e7;
const int bit = 29;
int cnt[maxv] = {};
int go[maxv][2] = {};
int tot = 1;

void add(int v, int d, int val)
{
	cnt[v]++;
	if (d == -1)
		return;
	if (!go[v][(val >> d) & 1])
		go[v][(val >> d) & 1] = ++tot;
	add(go[v][(val >> d) & 1], d - 1, val);
}

void get(int v, int d, int val, int& t_a)
{
	assert(cnt[v]);
	cnt[v]--;
	if (d == -1)
		return;
	for (int k = ((val >> d) & 1), l = 0; l < 2; k = 1 - k, ++l)
		if (go[v][k])
		{
			//cerr << k;
			get(go[v][k], d - 1, val, t_a);
			if (!cnt[go[v][k]])
				go[v][k] = 0;
			t_a += (k << d);
			return;
		}
}

int main()
{
	int n;
	cin >> n;
	vector<int> msg(n);
	for (int &i : msg)
		cin >> i;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		add(1, bit, x);
	}
	//assert(tot < maxv);
	for (int i : msg)
	{
		int out = 0;
		get(1, bit, i, out);
		//cerr << "\n";
		assert((i ^ out) >= 0);
		cout << (i ^ out) << " ";
	}
	return 0;
}