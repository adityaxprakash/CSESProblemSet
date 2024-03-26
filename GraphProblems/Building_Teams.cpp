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
int color[nlim] = {0};
vector<vi> adj(nlim);
int n, m;

bool dfs(int u, int c)
{
    color[u] = c;
    int newc = c == 1 ? 2 : 1;
    bool check = true;
    for (auto v : adj[u])
    {
        if (color[v] == 0)
            check = check && dfs(v, newc);
        else if (color[v] == c)
        {
            return false;
        }
    }
    return check;
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
    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
            ans = ans && dfs(i, 1);
    }
    if (ans)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}