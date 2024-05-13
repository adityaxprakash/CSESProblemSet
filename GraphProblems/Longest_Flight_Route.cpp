#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define vvi vector<vi>
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;
const ll inf = 1e18;

const int N = 1e5 + 1;

int dist[N];
vi adj[N];
int succ[N];
int n, m;

void dfs(int u)
{
    dist[u] = -1;
    if (u == n)
    {
        dist[u] = 1;
        return;
    }
    for (auto v : adj[u])
    {
        if (dist[v] == 0)
            dfs(v);
        if (dist[v] == -1)
            continue;
        if (dist[u] < dist[v] + 1)
        {
            dist[u] = 1 + dist[v];
            succ[u] = v;
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    dfs(1);

    if (dist[1] == -1)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    cout << dist[1] << "\n";
    int curr = 1;
    while (curr != n)
    {
        cout << curr << " ";
        curr = succ[curr];
    }
    cout << curr << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}