#include <bits/stdc++.h>

#define int int64_t

using namespace std;

char nxt['z' + 1] = {};
bool inc['z' + 1] = {};
int cnt['z' + 1] = {};

int32_t main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (char c : s)
            inc[c] = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (nxt[s[i]] == 0)
            {
                nxt[s[i]] = s[i + 1];
                cnt[s[i + 1]]++;
            }
            if (nxt[s[i]] != s[i + 1])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    string s;
    int C = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (inc[c])
            C++;
        if (cnt[c] > 1)
        {
            cout << "NO";
            return 0;
        }
        if (inc[c] && cnt[c] == 0)
        {
            for (char v = c; v > 0; v = nxt[v])
                s.push_back(v);
        }
    }
    if (s.length() == C)
        cout << s;
    else
        cout << "NO";
    return 0;
}
