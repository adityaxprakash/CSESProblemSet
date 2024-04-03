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

int opt, depth = -1;
vector<vi> dist(2, vi(lim, -1));

void dfs(int u, int p, int d, int i)
{
    dist[i][u] = dist[i][p] + 1;
    if (depth < d)
    {
        opt = u;
        depth = d;
    }
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u, d + 1, i);
    }
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
    dfs(1, 0, 0, 0);
    int a = opt;
    dfs(a, 0, 0, 0);
    int b = opt;
    dfs(b, 0, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << max(dist[0][i], dist[1][i]) << " ";
    }
    return 0;
}