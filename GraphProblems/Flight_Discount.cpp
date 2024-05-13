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

int n, m;
vpii adj[N];
vpii radj[N];
vector<ll> dist(N, inf);
vector<ll> rdist(N, inf);
vvi edges;

void dijkstra(int src, vector<ll> &distance, vpii adj[])
{
    distance[src] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().s;
        ll d = -pq.top().f;
        pq.pop();
        if (distance[u] < d)
            continue;
        for (pii nbr : adj[u])
        {
            int v = nbr.f;
            int c = nbr.s;
            if (distance[u] + c < distance[v])
            {
                distance[v] = distance[u] + c;
                pq.push({-distance[v], v});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        radj[b].pb({a, c});
        edges.pb({a, b, c});
    }

    int src = 1;
    int dest = n;

    dijkstra(src, dist, adj);
    dijkstra(dest, rdist, radj);

    ll cost = inf;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        cost = min(cost, dist[u] + rdist[v] + wt / 2);
    }
    cout << cost;
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