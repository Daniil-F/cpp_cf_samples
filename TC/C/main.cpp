#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t  main()
{
    int n;
    cin >> n;
    vector<bool> used(n + 5);
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (used[x])
            cnt++;
        else
            used[x] = 1;
    }
    cout << cnt;
    return 0;
}
