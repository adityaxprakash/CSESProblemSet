#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

const int lim = 2e5 + 1;
vector<int> adj[lim];
int n;
int matches = 0;

int dfs(int u, int p)
{
    int tot = 0;
    for (auto v : adj[u])
    {
        if (v != p)
        {
            tot += dfs(v, u);
        }
    }
    if (tot > 0)
    {
        matches++;
        return 0;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1);
    cout << matches;

    return 0;
}