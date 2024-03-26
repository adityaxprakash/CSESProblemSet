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
int src = -1;
int child = -1;
vi par;

bool dfs(int u)
{
    visited[u] = 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            par[v] = u;
            if (dfs(v))
                return true;
        }
        else if (v != par[u])
        {
            src = v;
            child = u;
            return true;
        }
    }
    return false;
}

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
    par = vi(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i))
            break;
    }
    if (src == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vi ans;
        ans.pb(src);
        while (child != src)
        {
            ans.pb(child);
            child = par[child];
        }
        ans.pb(src);
        cout << ans.size() << endl;
        for (auto e : ans)
            cout << e << " ";
    }

    return 0;
}