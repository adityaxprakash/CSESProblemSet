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
int visited[nlim];

void dfs(int u)
{
    visited[u] = 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
            dfs(v);
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int count = 0;
    vector<int> roads;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            roads.pb(i);
            dfs(i);
        }
    }
    cout << count - 1 << "\n";
    for (int i = 0; i < count - 1; i++)
        cout << roads[i] << " " << roads[i + 1] << "\n";
    return 0;
}