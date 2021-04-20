#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    map<int, int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x] = i;
    }
    map<int, int> arr2;
    for (auto p : arr)
        arr2[p.second] = p.first;
    cout << arr2.begin()->second;
    return 0;
}
