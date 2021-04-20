#include <bits/stdc++.h>

//#define int int64_t

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e6;
int tree[4 * maxn];
int tp[4 * maxn];

struct seg_tree
{
    void init(int v, int l, int r)
    {
        tree[v] = r - l;
        if (r == l + 1)
            return;
        int m = (r + l) / 2;
        init(2 * v + 1, l, m);
        init(2 * v + 2, m, r);
    }
    seg_tree(int n)
    {
        for (int i = 0; i < 4 * n; i++)
            tp[i] = 1;
        init(0, 0, n);
    }
    inline void push(int v, int l, int r)
    {
        if (tp[v] == 1)
            return;
        tree[v] = ((long long)tree[v] * tp[v]) % mod;
        if (r > l + 1)
        {
            tp[2 * v + 1] = ((long long)tp[2 * v + 1] * tp[v]) % mod;
            tp[2 * v + 2] = ((long long)tp[2 * v + 2] * tp[v]) % mod;
        }
        tp[v] = 1;
    }
    int seg_mult(int v, int l, int r, int tl, int tr, int val)
    {
        //cerr << "sm ";
        push(v, l, r);
        if (r <= tl || l >= tr)
            return tree[v];
        if (l >= tl && r <= tr)
        {
            tp[v] = val;
            push(v, l, r);
            return tree[v];
        }
        int m = (r + l) / 2;
        return tree[v] = (seg_mult(2 * v + 1, l, m, tl, tr, val) + seg_mult(2 * v + 2, m, r, tl, tr, val)) % mod;
    }
    int seg_sum(int v, int l, int r, int tl, int tr)
    {
        //cerr << "ss ";
        push(v, l, r);
        if (r <= tl || l >= tr)
            return 0;
        if (l >= tl && r <= tr)
            return tree[v];
        int m = (r + l) / 2;
        return (seg_sum(2 * v + 1, l, m, tl, tr) + seg_sum(2 * v + 2, m, r, tl, tr)) % mod;
    }
};

int32_t  main()
{
    int n, k;
    cin >> n >> k;
    seg_tree dp(n);
    long long fak = 1;
    for (int i = 1; i < n; i++)
    {
        //cerr << i << " ";
        fak *= i + 1;
        fak %= mod;
        int ndp = dp.seg_sum(0, 0, n, max(0, i - k), i);
        dp.seg_mult(0, 0, n, 0, i, i);
        dp.seg_mult(0, 0, n, i, i + 1, ndp);
    }
    cout << (fak - dp.seg_sum(0, 0, n, 0, n) + mod) % mod;
    return 0;
}
