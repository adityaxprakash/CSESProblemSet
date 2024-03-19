#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vi x(n);
    vi idx(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        idx[x[i]] = i;
    }
    vector<pair<int, int>> x_p(n);
    for (int i = 0; i < n; i++)
    {
        x_p[i].F = x[i];
        x_p[i].S = i + 1;
    }
    sort(all(x_p));
    int rounds = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (x_p[i].S >= x_p[i + 1].S)
            rounds++;
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        int c = min(a, b);
        b = a + b - c;
        a = c;
        int delta = 0;
        int prec = idx[x[a] - 1];
        int succ = idx[x[a] + 1];
        if (a < succ && succ < b)
            delta++;
        if (a < prec && prec < b)
            delta--;
        prec = idx[x[b] - 1];
        succ = idx[x[b] + 1];
        if (a < succ && succ < b)
            delta--;
        if (a < prec && prec < b)
            delta++;
        if (prec == a)
            delta++;
        if (succ == a)
            delta--;
        swap(idx[x[a]], idx[x[b]]);
        swap(x[a], x[b]);
        rounds += delta;
        cout << rounds << "\n";
    }

    return 0;
}