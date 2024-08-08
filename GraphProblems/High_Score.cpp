#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help std::cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 2505;
const ll inf = 1e18;

struct edge
{
    int src;
    int dest;
    int weight;
    edge(int _src, int _dest, int _weight) : src(_src), dest(_dest), weight(_weight) {}
};

vector<edge> edges;
vector<int> radj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for (auto v : radj[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.emplace_back(a, b, -w);
        radj[b].push_back(a);
    }
    vector<ll> dist(N, inf);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.src] == inf)
                continue;
            dist[e.dest] = min(dist[e.dest], dist[e.src] + e.weight);
        }
    }

    std ::fill(visited, visited + N, false);
    dfs(n);

    for (auto &e : edges)
    {
        if (dist[e.dest] > dist[e.src] + e.weight && visited[e.dest] && dist[e.src] != inf)
        {
            std ::cout << -1;
            return;
        }
    }
    std ::cout << -dist[n];
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