
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help cin.tie(NULL);
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;
const ll inf = 1e18;

const int N = 2e5 + 2;
const int l = 20;
vector<int> adj[N];
int tin[N];
int tout[N];
int dist[N];
int up[N][l + 1];
int n, q;
int timer = 0;

void dfs(int u = 1, int p = 1)
{
    tin[u] = ++timer;
    if (u != p)
        dist[u] = dist[p] + 1;
    else
        dist[u] = 0;
    up[u][0] = p;
    for (int i = 1; i <= l; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj[u])
    {
        if (v != p)
            dfs(v, u);
    }
    tout[u] = ++timer;
}

bool isAncestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (isAncestor(u, v))
        return u;
    if (isAncestor(v, u))
        return v;
    for (int i = l; i >= 0; i--)
    {
        if (!isAncestor(up[u][i], v))
        {
            u = up[u][i];
        }
    }
    return up[u][0];
}

void solve()
{
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        // cout << u << " " << v << endl;
        cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << endl;
    }
}

int main()
{
    send help;

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}