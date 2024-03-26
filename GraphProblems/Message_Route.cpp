#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

const int nlim = 1e5 + 10;
const int mlim = 2e5 + 10;
vector<vi> adj(nlim);
int n, m;
bool visited[nlim];
int dist[nlim];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<int> q;
    vi par(n + 1, -1);
    dist[1] = 1;
    visited[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        if (u == n)
        {
            break;
        }
        q.pop();
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = 1;
                par[v] = u;
                dist[v] = dist[u] + 1;
            }
        }
    }

    if (q.empty())
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> comp;
    cout << dist[n] << "\n";
    int curr = n;
    while (curr != -1)
    {
        comp.pb(curr);
        curr = par[curr];
    }
    reverse(all(comp));
    for (auto i : comp)
        cout << i << " ";

    return 0;
}