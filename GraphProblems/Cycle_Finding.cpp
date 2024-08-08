#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define send ios_base::sync_with_stdio(false);
#define help std::cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 2501;
const ll inf = 1e18;

struct edge
{
    int src;
    int dest;
    int weight;
    edge(int _src, int _dest, int _weight) : src(_src), dest(_dest), weight(_weight) {}
};

vector<edge> edges;
bool visited[N];
int parent[N];
ll dist[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    fill(dist, dist + N, 0);
    fill(visited, visited + N, false);
    fill(parent, parent + N, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.emplace_back(a, b, w);
    }

    // dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto &[u, v, w] : edges)
        {
            if (dist[u] == inf)
                continue;
            if (dist[v] > dist[u] + w)
            {
                parent[v] = u;
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto &[u, v, w] : edges)
    {
        if (dist[v] > dist[u] + w)
        {
            parent[v] = u;
            visited[v] = true;
            while (!visited[u])
            {
                visited[u] = true;
                u = parent[u];
            }
            stack<int> cycle;
            cycle.push(u);
            v = parent[u];
            while (v != u)
            {
                cycle.push(v);
                v = parent[v];
            }
            cycle.push(u);
            std ::cout << "YES\n";
            while (!cycle.empty())
            {
                cout << cycle.top() << " ";
                cycle.pop();
            }
            return;
        }
    }
    std ::cout << "NO\n";
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