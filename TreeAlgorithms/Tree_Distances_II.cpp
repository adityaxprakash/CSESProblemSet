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

vi childSum(lim, 0);
vi parSum(lim, 0);
vi sz(lim, 0);

int dfs(int u, int p)
{
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        sz[u] += dfs(v, u);
        childSum[u] += childSum[v];
    }
    childSum[u] += sz[u]++;
    return sz[u];
}

void pdfs(int u, int p)
{
    if (u != 1)
    {
        parSum[u] = childSum[p] - (sz[u] + childSum[u]) + n - sz[u] + parSum[p];
    }
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        pdfs(v, u);
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
    dfs(1, 0);
    pdfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << childSum[i] + parSum[i] << " ";

    return 0;
}