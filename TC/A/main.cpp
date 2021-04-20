#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main()
{
    vector<pair<int, int> > arr(6);
    for (auto &i : arr)
        cin >> i.second;
    for (int i = 0; i < 6; i++)
        arr[i].first = i;
    sort(arr.begin(), arr.end());
    while(next_permutation(arr.begin(), arr.end()))
    {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < 6; i++)
            if (i < 3)
                s1 += arr[i].second;
            else
                s2 += arr[i].second;
        if (s1 == s2)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
