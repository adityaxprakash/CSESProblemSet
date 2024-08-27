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
const ll mod = 1e9 + 7;
const ll inf = 1e18;

const int N = 1e5 + 1;

int n, m;
vpii adj[N];
vector<ll> dist(N, inf);
vector<ll> num_ways(N, 0);
vector<ll> max_edges(N, 0);
vector<ll> min_edges(N, inf);

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    int src = 1;
    dist[src] = 0;
    num_ways[src] = 1;
    min_edges[src] = 0;
    max_edges[src] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        ll d = -pq.top().f;
        ll u = pq.top().s;
        pq.pop();
        if (dist[u] < d)
            continue;
        for (pii nbr : adj[u])
        {
            int v = nbr.f;
            int c = nbr.s;
            if (dist[u] + c < dist[v])
            {
                num_ways[v] = num_ways[u];
                max_edges[v] = max_edges[u] + 1;
                min_edges[v] = min_edges[u] + 1;
                dist[v] = dist[u] + c;
                pq.push({-dist[v], v});
            }
            else if (dist[u] + c == dist[v])
            {
                num_ways[v] += num_ways[u];
                num_ways[v] %= mod;
                max_edges[v] = max(max_edges[v], max_edges[u] + 1);
                min_edges[v] = min(min_edges[v], min_edges[u] + 1);
            }
        }
    }
    cout << dist[n] << " " << num_ways[n] << " " << min_edges[n] << " " << max_edges[n] << "\n";
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
