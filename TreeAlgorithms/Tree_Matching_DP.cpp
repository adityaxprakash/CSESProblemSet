#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

const int lim = 2e5 + 1;
vector<int> adj[lim];
int n;
vi dp1(lim, 0);
vi dp2(lim, 0);

void dfs(int u, int p)
{
    int mx = -lim;
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        dp2[u] += max(dp1[v], dp2[v]);
        mx = max(mx, dp2[v] + 1 - max(dp1[v], dp2[v]));
    }
    dp1[u] = dp2[u] + mx;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, -1);
    cout << max(dp1[1], dp2[1]);

    return 0;
}