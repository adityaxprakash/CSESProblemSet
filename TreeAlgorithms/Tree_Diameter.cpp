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
int diameter = 0;

int dfs(int u, int p)
{
    vi heights;
    int h = 0;
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        int hv = dfs(v, u);
        h = max(h, hv + 1);
        heights.pb(hv);
    }
    sort(all(heights), greater<int>());
    if (heights.size() >= 2)
        diameter = max(diameter, heights[0] + heights[1] + 2);
    return h;
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
    cout << diameter;

    return 0;
}